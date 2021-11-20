/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:05:44 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/17 02:32:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "game.h"
#include "fixed_map.h"
#include <math.h>

void	draw_grid(t_buffer *buf)
{
	int32_t	x;
	int32_t	y;
	double	py;
	double	px;
	t_vec2	p;

	y = 0;
	while (y < buf->h / SQ_SIZE)
	{
		x = 0;
		py = (double)(y * SQ_SIZE);
		while (x < buf->w / SQ_SIZE)
		{
			px = (double)(x * SQ_SIZE);
			p.x = px + SQ_SIZE - PAD_SIZE;
			p.y = py + SQ_SIZE - PAD_SIZE;
			if (g_map[y][x] == 1)
				draw_rect(buf, (t_vec2){px, py}, p, 0xFFFFFF);
			else
				draw_rect(buf, (t_vec2){px, py}, p, 0x0);
			x++;
		}
		y++;
	}
}

void	draw_rect(t_buffer *buf, t_vec2 tl, t_vec2 br, uint32_t c)
{
	int32_t	i;
	int32_t	j;

	j = tl.y;
	while (j < (int32_t)br.y)
	{
		i = tl.x;
		while (i < (int32_t)br.x)
		{
			put_pixel(buf, i, j, c);
			i++;
		}
		j++;
	}
}

void	draw_rect_center(t_buffer *buf, t_vec2 center, t_vec2 wh, uint32_t c)
{
	t_vec2	tl;
	t_vec2	br;

	tl = (t_vec2){center.x - (wh.x / 2.0), center.y - (wh.y / 2.0)};
	br = vec2_add(tl, wh);
	draw_rect(buf, tl, br, c);
}
