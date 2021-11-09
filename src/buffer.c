/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:19:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 00:35:21 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include <libft/libft.h>
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

void	put_pixel(t_buffer *buf, int x, int y, unsigned int rgb)
{
	char	*dst;

	dst = buf->data + (y * buf->pitch + x * (buf->bpp / 8));
	*(unsigned int *)dst = rgb;
}
