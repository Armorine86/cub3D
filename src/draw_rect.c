/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:05:44 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/19 18:49:50 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "game.h"
#include <math.h>

void	draw_rect(t_buffer *buf, t_vec2 tl, t_vec2 br, uint32_t c)
{
	int32_t	i;
	int32_t	j;

	j = (int32_t)tl.y;
	while (j < (int32_t)br.y)
	{
		i = (int32_t)tl.x;
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
	br = ft_vec2_add(tl, wh);
	draw_rect(buf, tl, br, c);
}
