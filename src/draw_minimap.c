/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:49:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/06 14:52:20 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "config.h"

#define SCALE 3
#define OFFSET_X 14
#define OFFSET_Y 8

static void	draw_scaled_pixel(t_buffer *buf, t_vec2i pos, uint32_t c)
{
	int32_t	i;
	int32_t	j;

	j = 0;
	while (j < SCALE)
	{
		i = 0;
		while (i < SCALE)
		{
			put_pixel(buf, pos.x * SCALE + i,
				pos.y * SCALE + j, c);
			i++;
		}
		j++;
	}
}

static void	draw_player_circle(t_buffer *buf, t_player *p, uint32_t c)
{
	t_vec2	center;
	t_vec2	line_end;

	center = (t_vec2){MM_WIDTH / 2.0 + 5.0, MM_HEIGTH / 2.0};
	draw_circle(buf, center, MM_PLAYER_RADIUS, c);
	line_end = ft_vec2_add(center, ft_vec2_mul(p->dir, MM_LINE_LENGTH));
	draw_line(buf, center, line_end, c);
}

void	draw_minimap(t_buffer *buf, t_world *world, t_player *p)
{
	int32_t	x;
	int32_t	y;
	int32_t	mx;
	int32_t	my;

	clear_buffer(buf, MM_BG_COLOR);
	y = 0;
	while (y < MM_HEIGTH)
	{
		x = 0;
		while (x < MM_WIDTH)
		{
			mx = (x + (int32_t)p->pos.x * SCALE) / SCALE - OFFSET_X;
			my = (y + (int32_t)p->pos.y * SCALE) / SCALE - OFFSET_Y;
			if (mx >= 0 && mx < world->width && my >= 0 && my < world->height)
			{
				if (world->map[my][mx] == MAP_EMPTY)
					draw_scaled_pixel(buf, (t_vec2i){x, y}, MM_PATH_COLOR);
			}
			x++;
		}
		y++;
	}
	draw_player_circle(buf, p, MM_PLAYER_COLOR);
}
