/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:29:22 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/16 13:42:59 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	crosshair_v(t_buffer *buf, t_vec2i mid, uint32_t color)
{
	int32_t	x;
	int32_t	y;

	y = mid.y - 15;
	while (y < mid.y + 15)
	{
		x = mid.x - 1;
		while (x < mid.x + 1)
		{
			put_pixel(buf, x, y, color);
			x++;
		}
		y++;
	}
}

static void	crosshair_h(t_buffer *buf, t_vec2i mid, uint32_t color)
{
	int32_t	x;
	int32_t	y;

	y = mid.y - 1;
	while (y < mid.y + 1)
	{
		x = mid.x - 15;
		while (x < mid.x + 15)
		{
			put_pixel(buf, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_crosshair(t_buffer *buf, uint32_t color)
{
	t_vec2i	mid;

	mid = (t_vec2i){buf->w / 2, buf->h / 2};
	crosshair_h(buf, mid, color);
	crosshair_v(buf, mid, color);
}
