/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:54:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/11 18:00:10 by mleblanc         ###   ########.fr       */
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

void	draw_ray(t_buffer *buf, t_vec2 ray_start, t_vec2 ray_dir, uint32_t c)
{
	t_vec2	ray_len;
	t_vec2	unit_step;
	t_vec2i	map_sq;
	t_vec2i	step;
	bool	found;
	double	dist;

	unit_step.x = sqrt(1.0 + pow(ray_dir.y / ray_dir.x, 2.0));
	unit_step.y = sqrt(1.0 + pow(ray_dir.x / ray_dir.y, 2.0));
	map_sq = (t_vec2i){(int32_t)ray_start.x, (int32_t)ray_start.y};
	step = get_step(ray_dir);
	ray_len = fst_ray_len(ray_dir, ray_start, unit_step, map_sq);
	found = false;
	dist = 0.0;
	while (!found)
	{
		if (ray_len.x < ray_len.y)
		{
			map_sq.x += step.x;
			dist = ray_len.x;
			ray_len.x += unit_step.x;
		}
		else
		{
			map_sq.y += step.y;
			dist = ray_len.y;
			ray_len.y += unit_step.y;
		}
		if (g_map[map_sq.y][map_sq.x] == 1)
			found = true;
	}
	if (found)
	{
		t_vec2	hit;

		hit = vec2_add(vec2_mul(ray_dir, dist), ray_start);
		draw_line(buf, vec2_mul(ray_start, 100.0), vec2_mul(hit, 100.0), c);
	}
}

void	draw_field(t_buffer *buf, t_player *p, uint32_t c)
{
	double	angle_step;
	double	angle;
	t_vec2	dir;

	angle_step = deg_to_rad(5.0);
	angle = p->angle - deg_to_rad(40.0);
	while (angle < p->angle + deg_to_rad(40.0))
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		draw_ray(buf, p->pos, dir, c);
		angle += angle_step;
	}
}
