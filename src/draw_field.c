/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:34:34 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/11 19:35:02 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

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
