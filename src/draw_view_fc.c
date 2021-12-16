/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_fc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:29:02 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/16 13:05:05 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "texture.h"
#include "config.h"
#include "intersection.h"
#include "utils.h"
#include <math.h>

static t_vec2i	get_tex_coords(t_texture *t, t_vec2 pos, t_vec2i map)
{
	t_vec2i	tex;

	tex.x = (int32_t)(t->w * (pos.x - (double)map.x));
	tex.x = ft_clamp(tex.x, 0, t->w - 1);
	tex.y = (int32_t)(t->h * (pos.y - (double)map.y));
	tex.y = ft_clamp(tex.y, 0, t->h - 1);
	return (tex);
}

static uint32_t	get_pixel_color(t_texture *t, t_vec2i p, double dist)
{
	uint32_t	color;

	color = get_tex_pixel(t, p.x, p.y);
	color = get_color_fog(color, dist);
	return (color);
}

static void	draw_fc_x(t_buffer *buf, t_texture *fl, t_texture *c, t_fc *f)
{
	t_vec2i		tex_f;
	t_vec2i		tex_c;
	t_vec2i		map;
	uint32_t	color;

	while (f->iter.x < buf->w)
	{
		map = (t_vec2i){(int32_t)f->pos.x, (int32_t)f->pos.y};
		tex_f = get_tex_coords(fl, f->pos, map);
		tex_c = get_tex_coords(c, f->pos, map);
		f->pos = ft_vec2_add(f->pos, f->step);
		color = get_pixel_color(fl, tex_f, f->row_dist);
		put_pixel(buf, f->iter.x, f->iter.y, color);
		color = get_pixel_color(c, tex_c, f->row_dist);
		put_pixel(buf, f->iter.x, buf->h - f->iter.y - 1, color);
		f->iter.x++;
	}
}

static double	row_dist(int32_t y, int32_t h)
{
	int32_t	p;
	double	pos_z;

	p = y - (h / 2);
	pos_z = 0.5 * h;
	return (pos_z / p);
}

void	draw_fc(t_buffer *buf, t_player *p, t_texture *fl, t_texture *c)
{
	t_fc	f;
	t_vec2	ray0;
	t_vec2	ray1;

	f.iter.y = buf->h / 2;
	while (f.iter.y < buf->h)
	{
		f.iter.x = 0;
		ray0 = (t_vec2){p->dir.x - p->c_plane.x, p->dir.y - p->c_plane.y};
		ray1 = (t_vec2){p->dir.x + p->c_plane.x, p->dir.y + p->c_plane.y};
		f.row_dist = row_dist(f.iter.y, buf->h);
		f.step.x = f.row_dist * (ray1.x - ray0.x) / buf->w;
		f.step.y = f.row_dist * (ray1.y - ray0.y) / buf->w;
		f.pos.x = p->pos.x + f.row_dist * ray0.x;
		f.pos.y = p->pos.y + f.row_dist * ray0.y;
		draw_fc_x(buf, fl, c, &f);
		f.iter.y++;
	}
}
