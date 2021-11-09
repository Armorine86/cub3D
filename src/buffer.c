/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:19:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 15:05:53 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "libft/libft.h"
#include <mlx.h>
#include <stdint.h>
#include <stdlib.h>

t_buffer	*new_buffer(void *mlx, void *win, int width, int height)
{
	t_buffer	*b;

	b = ft_calloc(1, sizeof(t_buffer));
	b->mlx = mlx;
	b->win = win;
	b->width = width;
	b->height = height;
	b->img = mlx_new_image(mlx, width, height);
	b->data = mlx_get_data_addr(b->img, &b->bpp, &b->pitch, &b->endian);
	return (b);
}

void	destroy_buffer(t_buffer *buf)
{
	mlx_destroy_image(buf->mlx, buf->img);
	free(buf);
}

void	put_pixel(t_buffer *buf, int32_t x, int32_t y, uint32_t c)
{
	char	*dst;

	if (x < 0 || x >= buf->width)
		ft_putendl_fd("X out of bounds", 2);
	if (y < 0 || y >= buf->height)
		ft_putendl_fd("Y out of bounds", 2);
	dst = buf->data + (y * buf->pitch + x * (buf->bpp / 8));
	*(uint32_t *)dst = c;
}

void	clear(t_buffer *buf, uint32_t c)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (y < buf->height)
	{
		x = 0;
		while (x < buf->width)
		{
			put_pixel(buf, x, y, c);
			x++;
		}
		y++;
	}
}
