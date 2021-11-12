/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:54:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/11 19:34:44 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "fixed_map.h"
#include <math.h>

static t_vec2i	get_step(t_vec2 dir)
{
	t_vec2i	step;

	if (dir.x < 0.0)
		step.x = -1;
	else
		step.x = 1;
	if (dir.y < 0.0)
		step.y = -1;
	else
		step.y = 1;
	return (step);
}

static t_vec2	fst_ray_len(t_vec2 dir, t_vec2 pos, t_vec2 unit, t_vec2i map)
{
	t_vec2	ray_len;

	if (dir.x < 0.0)
		ray_len.x = (pos.x - (double)map.x) * unit.x;
	else
		ray_len.x = ((double)(map.x + 1.0) - pos.x) * unit.x;
	if (dir.y < 0.0)
		ray_len.y = (pos.y - (double)map.y) * unit.y;
	else
		ray_len.y = ((double)(map.y + 1.0) - pos.y) * unit.y;
	return (ray_len);
}

static void	intersect(t_buffer *buf, t_vec2 hit, t_vec2 pos, uint32_t c)
{
	draw_line(buf, vec2_mul(pos, SQ_SIZE), vec2_mul(hit, SQ_SIZE), c);
}

static double	distance(t_vec2 *len, t_vec2i *sq, t_vec2i step, t_vec2 unit)
{
	double	dist;

	if (len->x < len->y)
	{
		sq->x += step.x;
		dist = len->x;
		len->x += unit.x;
	}
	else
	{
		sq->y += step.y;
		dist = len->y;
		len->y += unit.y;
	}
	return (dist);
}

void	draw_ray(t_buffer *buf, t_vec2 pos, t_vec2 dir, uint32_t c)
{
	t_vec2	ray_len;
	t_vec2	unit_step;
	t_vec2i	map_sq;
	t_vec2i	step;
	double	dist;

	unit_step.x = sqrt(1.0 + pow(dir.y / dir.x, 2.0));
	unit_step.y = sqrt(1.0 + pow(dir.x / dir.y, 2.0));
	map_sq = (t_vec2i){(int32_t)pos.x, (int32_t)pos.y};
	step = get_step(dir);
	ray_len = fst_ray_len(dir, pos, unit_step, map_sq);
	dist = 0.0;
	while (dist < 100.0)
	{
		dist = distance(&ray_len, &map_sq, step, unit_step);
		if (g_map[map_sq.y][map_sq.x] == 1)
		{
			intersect(buf, vec2_add(vec2_mul(dir, dist), pos), pos, c);
			break ;
		}
	}
}
