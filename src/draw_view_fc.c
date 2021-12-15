/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_fc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:29:02 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/15 12:49:06 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "texture.h"
#include "config.h"
#include "intersection.h"
#include "utils.h"
#include <math.h>

typedef void	(*t_draw_pixel)(t_buffer *, t_texture *, t_fc *, uint32_t);

void	draw_ceiling(t_buffer *buf, t_texture *t, t_fc *f, uint32_t color)
{
	color = get_tex_pixel(t, f->tex.x, f->tex.y);
	put_pixel(buf, f->iter.x, buf->h - f->iter.y - 1, color);
}

void	draw_floor(t_buffer *buf, t_texture *t, t_fc *f, uint32_t color)
{
	color = get_tex_pixel(t, f->tex.x, f->tex.y);
	put_pixel(buf, f->iter.x, f->iter.y, color);
}

void	draw_fc_x(t_buffer *buf, t_texture *t, t_fc *f, t_draw_pixel fn)
{
	while (f->iter.x < buf->w)
	{
		f->map = (t_vec2i){(int32_t)f->pos.x, (int32_t)f->pos.y};
		f->tex.x = ft_clamp((int32_t)(t->w * (f->pos.x - f->map.x)),
				0, t->w - 1);
		f->tex.y = ft_clamp((int32_t)(t->h * (f->pos.y - f->map.y)),
				0, t->h - 1);
		f->pos.x += f->f_step.x;
		f->pos.y += f->f_step.y;
		fn(buf, t, f, f->color);
		f->iter.x++;
	}
}

void	draw_fc_y(t_buffer *buf, t_player *p, t_fc *f)
{
	f->iter.x = 0;
	f->ray0 = (t_vec2){p->dir.x - p->c_plane.x, p->dir.y - p->c_plane.y};
	f->ray1 = (t_vec2){p->dir.x + p->c_plane.x, p->dir.y + p->c_plane.y};
	f->p = f->iter.y - (buf->h / 2);
	f->pos_z = 0.5 * buf->h;
	f->row_dist = f->pos_z / f->p;
	f->f_step = (t_vec2){f->row_dist * (f->ray1.x - f->ray0.x) / buf->w,
		f->row_dist * (f->ray1.y - f->ray0.y) / buf->w};
	f->pos = (t_vec2){p->pos.x + f->row_dist * f->ray0.x,
		p->pos.y + f->row_dist * f->ray0.y};
}

void	draw_fc(t_buffer *buf, t_player *p, t_texture *fl, t_texture *c)
{
	t_fc	f;

	f.iter.y = buf->h / 2;
	while (f.iter.y < buf->h)
	{
		draw_fc_y(buf, p, &f);
		draw_fc_x(buf, c, &f, &draw_ceiling);
		draw_fc_y(buf, p, &f);
		draw_fc_x(buf, fl, &f, &draw_floor);
		f.iter.y++;
	}
}
