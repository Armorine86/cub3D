/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:54:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/11 15:14:26 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

static const int	g_map[6][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

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
	map_sq.x = (int32_t)ray_start.x;
	map_sq.y = (int32_t)ray_start.y;
	if (ray_dir.x < 0.0)
	{
		step.x = -1.0;
		ray_len.x = (ray_start.x - (double)map_sq.x) * unit_step.x;
	}
	else
	{
		step.x = 1.0;
		ray_len.x = ((double)(map_sq.x + 1.0) - ray_start.x) * unit_step.x;
	}
	if (ray_dir.y < 0.0)
	{
		step.y = -1.0;
		ray_len.y = (ray_start.y - (double)map_sq.y) * unit_step.y;
	}
	else
	{
		step.y = 1.0;
		ray_len.y = ((double)(map_sq.y + 1.0) - ray_start.y) * unit_step.y;
	}

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

	angle_step = deg_to_rad(1.0);
	angle = p->angle - deg_to_rad(30.0);
	while (angle < p->angle + deg_to_rad(30.0))
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		draw_ray(buf, p->pos, dir, c);
		angle += angle_step;
	}
}
