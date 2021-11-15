/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:42:06 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/15 15:00:03 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
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

static t_hit	distance(t_vec2 *len, t_vec2i *sq, t_vec2i step, t_vec2 unit)
{
	t_hit	hit;

	if (len->x < len->y)
	{
		sq->x += step.x;
		hit.dist = len->x;
		len->x += unit.x;
		if (step.x == 1)
			hit.side = WEST;
		else
			hit.side = EAST;
	}
	else
	{
		sq->y += step.y;
		hit.dist = len->y;
		len->y += unit.y;
		if (step.y == 1)
			hit.side = NORTH;
		else
			hit.side = SOUTH;
	}
	return (hit);
}

bool	intersect(t_vec2 pos, t_vec2 dir, t_hit *hit)
{
	t_vec2	ray_len;
	t_vec2	unit_step;
	t_vec2i	map_p;
	t_vec2i	step;

	unit_step.x = sqrt(1.0 + pow(dir.y / dir.x, 2.0));
	unit_step.y = sqrt(1.0 + pow(dir.x / dir.y, 2.0));
	map_p = (t_vec2i){(int32_t)pos.x, (int32_t)pos.y};
	step = get_step(dir);
	ray_len = fst_ray_len(dir, pos, unit_step, map_p);
	while (hit->dist < MAX_DIST)
	{
		*hit = distance(&ray_len, &map_p, step, unit_step);
		if (g_map[map_p.y][map_p.x] == 1)
		{
			hit->pos = vec2_add(vec2_mul(dir, hit->dist), pos);
			return (true);
		}
	}
	return (false);
}
