/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:27:03 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/18 17:15:43 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "config.h"
#include "intersection.h"
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
	double		perp_dist;
	t_lineinfo	info;

	theta = wrap_angle(p->angle - atan(ray.y / ray.x));
	perp_dist = hit.dist * cos(theta);
	info.wall_h = h / perp_dist;
	info.wall_h  = ft_abs(info.wall_h);
	info.start = (-info.wall_h  / 2) + (h / 2);
	if (info.start < 0)
		info.start = 0;
	info.end = (info.wall_h / 2) + (h / 2);
	if (info.end >= h)
		info.end = h - 1;
	if (hit.side == EAST || hit.side == WEST)
		info.wall_x = p->pos.y + perp_dist * ray.y;
	else
		info.wall_x = p->pos.x + perp_dist * ray.x;
	info.wall_x -= floor(info.wall_x);
	return (info);
}

void	draw_line_tex(t_buffer *buf, t_texture *t, t_lineinfo info, t_side s, int x)
{
	t_vec2i	tex;
	int32_t	y;
	double	pos;
	double	step;
	uint32_t	c;

	tex.x = (int32_t)(info.wall_x * (double)t->w);
	(void)s;
	// if ((s == EAST || s == WEST) && info.ray_dir.x > 0);
		// tex.x = t->w - tex.x - 1;
	// else if ((s == NORTH || s == SOUTH) && info.ray_dir.y < 0);
		// tex.x = t->w - tex.x - 1;
	step = 1.0 * (double)t->h / info.wall_h;
	pos = (info.start - t->h / 2 + info.wall_h / 2) * step;
	y = info.start;
	while (y < info.end)
	{
		tex.y = ft_clamp(pos, 0, t->h);
		pos += step;
		c = get_pixel(t, tex.x, tex.y);
		put_pixel(buf, x, y, c);
		y++;
	}
}

void	draw_view(t_buffer *buf, t_player *p, t_texture *t)
{
	t_lineinfo	info;
	t_hit		hit;
	int32_t		x;

	x = 0;
	while (x < buf->w)
	{
		info.ray_dir = get_ray_dir(p, x, buf->w);
		intersect(p->pos, info.ray_dir, &hit);
		info = line_info(p, info.ray_dir, hit, buf->h);
		if (hit.side == EAST)
			draw_line_tex(buf, t, info, hit.side, x);
		else if (hit.side == WEST)
			draw_line_tex(buf, t, info, hit.side, x);
		else if (hit.side == NORTH)
			draw_line_tex(buf, t, info, hit.side, x);
		else
			draw_line_tex(buf, t, info, hit.side, x);
		x++;
	}
}
