/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:27:03 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/16 12:46:57 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "config.h"
#include "intersection.h"
#include <math.h>

void	draw_view(t_buffer *buf, t_player *p)
{
	double	angle_step;
	double	angle;
	double	wall_h;
	double	offset;
	t_hit	hit;
	int32_t	i;

	angle_step = deg_to_rad(2.0);
	angle = p->angle - deg_to_rad(60.0);
	i = 0;
	while (i < 60)
	{
		intersect(p->pos, p->dir, &hit);
		wall_h = HEIGHT / hit.dist;
		if (wall_h > HEIGHT)
			wall_h = HEIGHT;
		offset = wall_h / 2;
		draw_rect(buf, hit.pos, (t_vec2){i + 8, wall_h + offset}, 0x0000FF);
		angle += angle_step;
		i++;
	}
}
