/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:10:27 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 22:46:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "utils.h"
#include <libft/libft.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

static void	h_line(t_buffer *buf, t_vec2 p0, t_vec2 p1, uint32_t c)
{
	float	a;
	float	b;
	int32_t	i;

	a = 0.0f;
	if (p0.x != p1.x)
		a = (p1.y - p0.y) / (p1.x - p0.x);
	if (p1.x < p0.x)
		vec2_swap(&p0, &p1);
	b = p1.y - (a * p1.x);
	i = (int32_t)p0.x;
	while (i < (int32_t)p1.x)
	{
		put_pixel(buf, i, (int32_t)(a * (float)i + b), c);
		i++;
	}
}

void	v_line(t_buffer *buf, t_vec2 p0, t_vec2 p1, uint32_t c)
{
	float	a;
	float	b;
	int32_t	i;

	if (p1.y < p0.y)
		vec2_swap(&p0, &p1);
	a = 0.0f;
	if (p0.y != p1.y)
		a = (p1.x - p0.x) / (p1.y - p0.y);
	b = p1.x - (a * p1.y);
	i = (int32_t)p0.y;
	while (i < (int32_t)p1.y)
	{
		put_pixel(buf, (int32_t)(a * (float)i + b), i, c);
		i++;
	}
}

void	draw_line(t_buffer *buf, t_vec2 p0, t_vec2 p1, uint32_t c)
{
	float	a;

	a = 0.0f;
	if (p0.x != p1.x)
		a = (p1.y - p0.y) / (p1.x - p0.x);
	if (p0.x != p1.x && a >= -1.0 && a <= 1.0f)
		h_line(buf, p0, p1, c);
	else
		v_line(buf, p0, p1, c);
}