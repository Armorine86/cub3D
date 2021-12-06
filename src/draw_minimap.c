/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:49:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/05 21:48:25 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "config.h"

// static void	draw_scaled_pixel(t_buffer *buf, t_vec2i pos, uint32_t c)
// {
// 	int32_t	i;
// 	int32_t	j;

// 	j = 0;
// 	while (j < MINIMAP_SCALE)
// 	{
// 		i = 0;
// 		while (i < MINIMAP_SCALE)
// 		{
// 			put_pixel(buf, pos.x * MINIMAP_SCALE + i,
// 				pos.y * MINIMAP_SCALE + j, c);
// 			i++;
// 		}
// 		j++;
// 	}
// }

void	draw_minimap(t_buffer *buf, t_world *world, t_player *p)
{
	t_vec2	tl;
	t_vec2	br;
	t_vec2	center;

	(void)world;
	tl = (t_vec2){10.0, 10.0};
	br = (t_vec2){250.0, 150.0};
	center = (t_vec2){(br.x - tl.x) / 2 + tl.x, (br.y - tl.y) / 2 + tl.y};
	draw_rect(buf, tl, br, 0xCCCCCC);
	draw_circle(buf, center, 3.0, 0xFF0000);
	draw_line(buf, center, ft_vec2_add(center, ft_vec2_mul(p->dir, 10.0)), 0xFF0000);
}
