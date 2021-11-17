/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:27:03 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/17 02:53:57 by mleblanc         ###   ########.fr       */
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

static t_vec2i	line_pos(t_player *p, t_vec2 ray_dir, double dist, int32_t h)
{
	double	theta;
	int32_t	line_h;
	t_vec2i	pos;

	theta = wrap_angle(p->angle - atan(ray_dir.y / ray_dir.x));
	line_h = h / (dist * cos(theta));
	pos.x = (-line_h / 2) + (h / 2);
	if (pos.x < 0)
		pos.x = 0;
	pos.y = (line_h / 2) + (h / 2);
	if (pos.y >= h)
		pos.y = h - 1;
	return (pos);
}

void	draw_view(t_buffer *buf, t_player *p)
{
	t_vec2	ray_dir;
	t_vec2i	line_p;
	t_hit	hit;
	int32_t	x;

	x = 0;
	while (x < buf->w)
	{
		ray_dir = get_ray_dir(p, x, buf->w);
		intersect(p->pos, ray_dir, &hit);
		line_p = line_pos(p, ray_dir, hit.dist, buf->h);
		if (hit.side == EAST || hit.side == WEST)
			draw_line(buf, (t_vec2){x, line_p.x},
				(t_vec2){x, line_p.y}, 0x0000FF / 2);
		else
			draw_line(buf, (t_vec2){x, line_p.x},
				(t_vec2){x, line_p.y}, 0x0000FF);
		x++;
	}
}
