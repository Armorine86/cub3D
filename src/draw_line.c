/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:10:27 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/01 07:07:36 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "utils.h"
#include <libft/libft.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

static void	flip_sign(int32_t *v1, int32_t *v2)
{
	*v1 = -(*v1);
	*v2 = -(*v2);
}

static void	plotline_low(t_buffer *buf, t_vec2 p0, t_vec2 p1, uint32_t c)
{
	t_vec2i	delta;
	t_vec2i	it;
	int32_t	yi;
	int32_t	d;

	delta = (t_vec2i){(int32_t)(p1.x - p0.x), (int32_t)(p1.y - p0.y)};
	yi = 1;
	if (delta.y < 0)
		flip_sign(&yi, &delta.y);
	d = (delta.y * 2) - delta.x;
	it = (t_vec2i){(int32_t)p0.x, (int32_t)p0.y};
	while (it.x < (int32_t)p1.x)
	{
		put_pixel(buf, it.x, it.y, c);
		if (d > 0)
		{
			it.y += yi;
			d += 2 * (delta.y - delta.x);
		}
		else
			d += 2 * delta.y;
		it.x++;
	}
}

static void	plotline_high(t_buffer *buf, t_vec2 p0, t_vec2 p1, uint32_t c)
{
	t_vec2i	delta;
	t_vec2i	it;
	int32_t	xi;
	int32_t	d;

	delta = (t_vec2i){(int32_t)(p1.x - p0.x), (int32_t)(p1.y - p0.y)};
	xi = 1;
	if (delta.x < 0)
		flip_sign(&xi, &delta.x);
	d = (2 * delta.x) - delta.y;
	it = (t_vec2i){(int32_t)p0.x, (int32_t)p0.y};
	while (it.y < (int32_t)p1.y)
	{
		put_pixel(buf, it.x, it.y, c);
		if (d > 0)
		{
			it.x += xi;
			d += 2 * (delta.x - delta.y);
		}
		else
			d += 2 * delta.x;
		it.y++;
	}
}

void	draw_line(t_buffer *buf, t_vec2 p0, t_vec2 p1, uint32_t c)
{
	if (ft_abs((int32_t)(p1.y - p0.y)) < ft_abs((int32_t)(p1.x - p0.x)))
	{
		if ((int32_t)p0.x > (int32_t)p1.x)
			vec2_swap(&p0, &p1);
		plotline_low(buf, p0, p1, c);
	}
	else
	{
		if ((int32_t)p0.y > (int32_t)p1.y)
			vec2_swap(&p0, &p1);
		plotline_high(buf, p0, p1, c);
	}
}
