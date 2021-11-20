/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:27:03 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/20 10:18:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "texture.h"
#include "config.h"
#include "intersection.h"
#include "utils.h"
#include <math.h>

static t_vec2	get_ray_dir(t_player *p, int32_t x, int32_t w)
{
	double	cam_x;
	t_vec2	ray_dir;

	cam_x = (2 * x) / (double)w - 1;
	ray_dir.x = p->dir.x + p->c_plane.x * cam_x;
	ray_dir.y = p->dir.y + p->c_plane.y * cam_x;
	return (ray_dir);
}

static t_lineinfo	line_info(t_player *p, t_vec2 ray, t_hit hit, int32_t h)
{
	double		theta;
	double		view_dist;
	t_lineinfo	info;

	info.ray_dir = ray;
	info.hit = hit;
	theta = wrap_angle(p->angle - atan(ray.y / ray.x));
	view_dist = fabs(hit.dist * cos(theta));
	info.h = h / view_dist;
	info.start = (-info.h / 2) + (h / 2);
	if (info.start < 0)
		info.start = 0;
	info.end = (info.h / 2) + (h / 2);
	if (info.end >= h)
		info.end = h - 1;
	if (is_vertical(hit.side))
		info.wall_x = p->pos.y + view_dist * ray.y;
	else
		info.wall_x = p->pos.x + view_dist * ray.x;
	info.wall_x -= floor(info.wall_x);
	return (info);
}

static uint32_t	get_color(uint32_t c, double dist)
{
	double	visibility;

	if (!isnormal(dist))
		dist = 0;
	visibility = exp(-pow(dist * FOG_DENSITY, FOG_GRADIENT));
	visibility = ft_clampd(visibility, 0.0, 1.0);
	return (argb_mul(c, visibility));
}

void	draw_line_tex(t_buffer *buf, t_texture *t, t_lineinfo line, int32_t x)
{
	int32_t		tex_x;
	double		tex_y;
	double		tex_step;
	int32_t		y;
	uint32_t	color;

	tex_x = line.wall_x * t->w;
	if (is_vertical(line.hit.side) && line.ray_dir.x < 0)
		tex_x = t->w - tex_x - 1;
	else if (is_horizontal(line.hit.side) && line.ray_dir.y > 0)
		tex_x = t->w - tex_x - 1;
	tex_step = t->h / (double)line.h;
	tex_y = (line.start - buf->h / 2 + line.h / 2) * tex_step;
	y = line.start;
	while (y < line.end)
	{
		color = get_tex_pixel(t, tex_x, ft_clamp(tex_y, 0, t->h - 1));
		tex_y += tex_step;
		put_pixel(buf, x, y, get_color(color, line.hit.dist));
		y++;
	}
}

void	draw_view(t_buffer *buf, t_player *p, t_texture *t)
{
	t_vec2		ray_dir;
	t_lineinfo	info;
	t_hit		hit;
	int32_t		x;

	x = 0;
	while (x < buf->w)
	{
		ray_dir = get_ray_dir(p, x, buf->w);
		intersect(p->pos, ray_dir, &hit);
		info = line_info(p, ray_dir, hit, buf->h);
		if (hit.side == EAST)
			draw_line_tex(buf, t, info, x);
		else if (hit.side == WEST)
			draw_line_tex(buf, t, info, x);
		else if (hit.side == NORTH)
			draw_line_tex(buf, t, info, x);
		else
			draw_line_tex(buf, t, info, x);
		x++;
	}
}
