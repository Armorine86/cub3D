/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:05:44 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 18:06:08 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "game.h"
#include <math.h>

static const int	g_map[6][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 1, 1, 1},
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
	t_vec2	line_end;

	draw_circle(buf, player->pos, 10.0f, 0xFF0000);
	line_end = vec2_add(player->pos, vec2_mul(player->dir, 30.0f));
	draw_line(buf, player->pos, line_end, 0xFF0000);
}

void	draw_rect_center(t_buffer *buf, t_vec2 center, t_vec2 wh, uint32_t c)
{
	t_vec2	tl;
	t_vec2	br;

	tl = (t_vec2){center.x - (wh.x / 2.0f), center.y - (wh.y / 2.0f)};
	br = vec2_add(tl, wh);
	draw_rect(buf, tl, br, c);
}

static void	draw_circle_lines(t_buffer *buf, t_vec2 xy, t_vec2 cen, uint32_t c)
{
	draw_line(buf,
		(t_vec2){xy.x + cen.x, xy.y + cen.y},
		(t_vec2){-xy.x + cen.x, xy.y + cen.y},
		c);
	draw_line(buf,
		(t_vec2){xy.x + cen.x, -xy.y + cen.y},
		(t_vec2){-xy.x + cen.x, -xy.y + cen.y},
		c);
	draw_line(buf,
		(t_vec2){xy.y + cen.x, xy.x + cen.y},
		(t_vec2){-xy.y + cen.x, xy.x + cen.y},
		c);
	draw_line(buf,
		(t_vec2){xy.y + cen.x, -xy.x + cen.y},
		(t_vec2){-xy.y + cen.x, -xy.x + cen.y},
		c);
}

void	draw_circle(t_buffer *buf, t_vec2 center, float r, uint32_t c)
{
	int32_t	x;
	int32_t	y;
	int32_t	p;

	x = (int32_t)r;
	y = 0;
	p = 1 - (int32_t)r;
	if (r > 0.0f)
		draw_line(buf, (t_vec2){(float)x + center.x, center.y},
			(t_vec2){(float)-x + center.x, center.y}, c);
	while (x > y)
	{
		y++;
		if (p <= 0)
			p += 2 * y + 1;
		else
		{
			x--;
			p += 2 * y - 2 * x + 1;
		}
		if (x < y)
			break ;
		draw_circle_lines(buf, (t_vec2){(float)x, (float)y},
			(t_vec2){center.x, center.y}, c);
	}
}
