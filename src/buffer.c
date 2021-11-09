/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:19:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 12:38:12 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include <mlx.h>
#include <stdlib.h>

t_buffer	*new_buffer(void *mlx_ptr, int width, int height)
{
	t_buffer	*b;

	b = ft_calloc(1, sizeof(t_buffer));
	b->mlx = mlx_ptr;
	b->img = mlx_new_image(mlx_ptr, width, height);
	b->data = mlx_get_data_addr(b->img, &b->bpp, &b->pitch, &b->endian);
	return (b);
}

void	destroy_buffer(t_buffer *buf)
{
	mlx_destroy_image(buf->mlx, buf->img);
	free(buf);
}

void	put_pixel(t_buffer *buf, int32_t x, int32_t y, uint32_t trgb)
{
	char	*dst;

	dst = buf->data + (y * buf->pitch + x * (buf->bpp / 8));
	*(uint32_t *)dst = trgb;
}

void	draw_rect(t_buffer *buf, t_vec2i tl, t_vec2i br, uint32_t c)
{
	int32_t	width;
	int32_t	height;
	int32_t	i;
	int32_t	j;

	width = br.x - tl.x;
	height = br.y - tl.y;
	j = tl.y;
	while (j < height)
	{
		i = tl.x;
		while (i < width)
		{
			put_pixel(buf, i, j, c);
			i++;
		}
		j++;
	}
}

void	draw_line(t_buffer *buf, t_vec2i p0, t_vec2i p1, uint32_t c)
{
	float	a;
	float	b;
	int32_t	i;

	a = (float)(p1.y - p0.y) / (float)(p1.x - p0.x);
	b = (float)p1.y - (a * (float)p1.x);
	if (a > 1 || a < -1)
	{
		i = p0.y;
		while (i < p1.y)
		{
			put_pixel(buf, (i - b) / a, i, c);
			i++;
		}
	}
	else
	{
		i = p0.x;
		while (i < p1.x)
		{
			put_pixel(buf, i, (a * i) + b, c);
			i++;
		}
	}
}
