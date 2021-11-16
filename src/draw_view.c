/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:27:03 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/16 15:32:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "config.h"
#include "intersection.h"
#include <math.h>

void	draw_view(t_buffer *buf, t_player *p)
{
	t_vec2	ray_dir;
	int32_t	draw_start;
	int32_t	draw_end;
	int32_t	wall_h;
	double	cam_x;
	t_hit	hit;
	int32_t	x;

	x = 0;
	while (x < WIDTH / 2)
	{
		cam_x = (2 * x) / (double)(WIDTH / 2) - 1;
		ray_dir.x = p->dir.x + p->c_plane.x * cam_x;
		ray_dir.y = p->dir.y + p->c_plane.y * cam_x;
		intersect(p->pos, ray_dir, &hit);
		wall_h = HEIGHT / hit.perpdist;
		draw_start = (-wall_h / 2) + (HEIGHT / 2);
		if (draw_start < 0)
			draw_start = 0;
		draw_end = (wall_h / 2) + (HEIGHT / 2);
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;
		if (hit.side == EAST || hit.side == WEST)
			draw_line(buf, (t_vec2){x, draw_start}, (t_vec2){x, draw_end}, 0x0000FF / 2);
		else
			draw_line(buf, (t_vec2){x, draw_start}, (t_vec2){x, draw_end}, 0x0000FF);
		x++;
	}
}
