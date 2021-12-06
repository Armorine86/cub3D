/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:49:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/06 00:41:22 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "config.h"

static void	draw_scaled_pixel(t_buffer *buf, t_vec2i pos, uint32_t c)
{
	int32_t	i;
	int32_t	j;

	j = 0;
	while (j < MINIMAP_SCALE)
	{
		i = 0;
		while (i < MINIMAP_SCALE)
		{
			put_pixel(buf, pos.x * MINIMAP_SCALE + i,
				pos.y * MINIMAP_SCALE + j, c);
			i++;
		}
		j++;
	}
}

void	draw_minimap(t_buffer *buf, t_world *world, t_player *p)
{
	t_vec2	center;
	int32_t	x;
	int32_t	y;
	int32_t	mx;
	int32_t	my;
	double	rx;
	double	ry;

	clear_buffer(buf, 0xCCCCCC);
	rx = MINIMAP_W / world->width;
	ry = MINIMAP_H / world->height;
	center = (t_vec2){MINIMAP_W / 2.0, MINIMAP_H / 2.0};
	y = 0;
	while (y < MINIMAP_H)
	{
		x = 0;
		while (x < MINIMAP_W)
		{
			mx = (x - (int32_t)p->pos.x) / MINIMAP_SCALE;
			my = (y - (int32_t)p->pos.y) / MINIMAP_SCALE;
			if (mx >= 0 && mx < world->width && my >= 0 && my < world->height)
			{
				if (world->map[my][mx] == MAP_EMPTY)
					draw_scaled_pixel(buf, (t_vec2i){x, y}, 0x00CCFF);
			}
			x++;
		}
		y++;
	}
	draw_circle(buf, center, 3.0, 0xFF0000);
	draw_line(buf, center, ft_vec2_add(center, ft_vec2_mul(p->dir, 10.0)), 0xFF0000);
}
