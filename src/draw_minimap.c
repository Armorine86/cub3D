/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:49:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/03 20:40:38 by mleblanc         ###   ########.fr       */
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

void	draw_minimap(t_buffer *buf, t_world *world)
{
	t_vec2	tl;
	t_vec2	br;
	int32_t	i;
	int32_t	j;

	tl = (t_vec2){MINIMAP_SCALE, MINIMAP_SCALE};
	br = (t_vec2){250.0, 150.0};
	draw_rect(buf, tl, br, 0xCCCCCC);
	j = 0;
	while (j < world->height)
	{
		i = 0;
		while (i < world->width)
		{
			if (world->map[j][i] == MAP_EMPTY)
				draw_scaled_pixel(buf, (t_vec2i){i, j}, 0x55FF);
			i++;
		}
		j++;
	}
	draw_circle(buf, (t_vec2){(br.x - tl.x) / 2 + tl.x, (br.y - tl.y) / 2 + tl.y}, 3.0, 0xFF0000);
}
