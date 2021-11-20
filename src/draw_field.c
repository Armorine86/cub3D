/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:34:34 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/18 22:18:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "config.h"
#include <math.h>

void	draw_field(t_buffer *buf, t_player *p, uint32_t c)
{
	double	angle_step;
	double	angle;
	double	end;
	t_vec2	dir;

	angle_step = deg_to_rad(0.02);
	angle = p->angle - deg_to_rad(FOV / 2.0);
	end = p->angle + deg_to_rad(FOV / 2.0);
	while (angle <= end)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		draw_ray(buf, p->pos, dir, c);
		angle += angle_step;
	}
}
