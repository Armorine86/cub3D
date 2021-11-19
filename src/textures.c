/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:50:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/19 08:47:19 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include "game.h"
#include "texture.h"

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
	if (!t)
		return (NULL);
	t->img = mlx_xpm_file_to_image(mlx, file, &t->width, &t->height);
	if (!t->img)
	{
		free_texture(mlx, t);
		return (NULL);
	}
	t->data = mlx_get_data_addr(t->img, &t->bpp, &t->pitch, &t->endian);
	return (t);
}

