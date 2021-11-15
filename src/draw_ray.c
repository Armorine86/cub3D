/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:54:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/15 15:18:53 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "fixed_map.h"
#include "intersection.h"

void	draw_ray(t_buffer *buf, t_vec2 pos, t_vec2 dir, uint32_t c)
{
	t_hit	hit;

	(void)c;
	if (intersect(pos, dir, &hit))
	{
		if (hit.side == EAST)
			draw_line(buf, vec2_mul(pos, SQ_SIZE),
				vec2_mul(hit.pos, SQ_SIZE), 0xFF00);
		else if (hit.side == WEST)
			draw_line(buf, vec2_mul(pos, SQ_SIZE),
				vec2_mul(hit.pos, SQ_SIZE), 0xFF);
		else if (hit.side == NORTH)
			draw_line(buf, vec2_mul(pos, SQ_SIZE),
				vec2_mul(hit.pos, SQ_SIZE), 0xFFFF00);
		else if (hit.side == SOUTH)
			draw_line(buf, vec2_mul(pos, SQ_SIZE),
				vec2_mul(hit.pos, SQ_SIZE), 0xFFFF);
	}
}
