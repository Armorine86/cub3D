/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:05:44 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 23:22:03 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "game.h"

static const int	g_map[6][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

void	draw_grid(t_buffer *buf)
{
	int32_t	x;
	int32_t	y;
	float	py;
	float	px;
	t_vec2	p;

	y = 0;
	while (y < HEIGHT / SQUARE_SIZE)
	{
		x = 0;
		py = (float)(y * SQUARE_SIZE);
		while (x < WIDTH / SQUARE_SIZE)
		{
			px = (float)(x * SQUARE_SIZE);
			p.x = px + SQUARE_SIZE - PAD_SIZE;
			p.y = py + SQUARE_SIZE - PAD_SIZE;
			if (g_map[y][x] == 1)
				draw_rect(buf, (t_vec2){px, py}, p, 0xFFFFFF);
			else
				draw_rect(buf, (t_vec2){px, py}, p, 0x0);
			x++;
		}
		y++;
	}
}

void	draw_player(t_buffer *buf, t_player *player)
{
	t_vec2	wh;
	t_vec2	line_end;

	wh = (t_vec2){10.0f, 10.0f};
	draw_rect_center(buf, player->pos, wh, 0xFFFF00);
	line_end = vec2_add(player->pos, vec2_mul(player->dir, 30.0f));
	draw_line(buf, player->pos, line_end, 0xFFFF00);
}

void	draw_rect_center(t_buffer *buf, t_vec2 center, t_vec2 wh, uint32_t c)
{
	t_vec2	tl;
	t_vec2	br;

	tl = (t_vec2){center.x - (wh.x / 2.0f), center.y - (wh.y / 2.0f)};
	br = vec2_add(tl, wh);
	draw_rect(buf, tl, br, c);
}
