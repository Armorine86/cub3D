/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:50:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/18 16:52:46 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include <libft/libft.h>
#include <stdlib.h>
#include <mlx.h>

void	free_texture(void *mlx, t_texture *t)
{
	if (mlx && t && t->img)
		mlx_destroy_image(mlx, t->img);
	free(t);
}

t_texture	*new_texture(void *mlx, const char *file)
{
	t_texture	*t;

	t = ft_calloc(1, sizeof(t_texture));
	t->img = mlx_xpm_file_to_image(mlx, file, &t->w, &t->h);
	if (!t->img)
	{
		free_texture(mlx, t);
		return (NULL);
	}
	t->data = mlx_get_data_addr(t->img, &t->bpp, &t->pitch, &t->endian);
	return (t);
}

uint32_t	get_pixel(t_texture *t, int32_t x, int32_t y)
{
	char	*src;

	if (x < 0 || x >= t->w)
		return (0);
	if (y < 0 || y >= t->h)
		return (0);
	src = t->data + (y * t->pitch + x * (t->bpp / 8));
	return (*(uint32_t *)src);
}
