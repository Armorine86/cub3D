/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:51:06 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/01 07:04:23 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <limits.h>

uint32_t	make_argb(uint8_t t, uint8_t r, uint8_t g, uint8_t b)
{
	return ((uint32_t)(t << 24 | r << 16 | g << 8 | b));
}

uint32_t	argb_mul(uint32_t c, double factor)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	factor = ft_clampd(factor, 0.0, UINT8_MAX);
	r = c >> 16;
	g = c >> 8;
	b = c;
	r = (uint8_t)((double)r * factor);
	g = (uint8_t)((double)g * factor);
	b = (uint8_t)((double)b * factor);
	return (make_argb(c >> 24, r, g, b));
}

void	vec2_swap(t_vec2 *a, t_vec2 *b)
{
	t_vec2	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

bool	is_vertical(t_side side)
{
	return (side == EAST || side == WEST);
}

bool	is_horizontal(t_side side)
{
	return (side == NORTH || side == SOUTH);
}
