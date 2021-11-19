/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:50:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/18 14:32:56 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include "game.h"
#include "textures.h"

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

void	load_texture(t_world *world, void *mlx, char **info)
{
	int32_t	n;

	n = 0;
	while (n < N_TEXTURES)
	{
		if (!(ft_strncmp(info[n], "NO", 2)))
			world->tex[NORTH] = new_texture(mlx, &info[n][3]);
		else if (!(ft_strncmp(info[n], "SO", 2)))
			world->tex[SOUTH] = new_texture(mlx, &info[n][3]);
		else if (!(ft_strncmp(info[n], "WE", 2)))
			world->tex[WEST] = new_texture(mlx, &info[n][3]);
		else if (!(ft_strncmp(info[n], "EA", 2)))
			world->tex[EAST] = new_texture(mlx, &info[n][3]);
		n++;
	}
	ft_strarr_free(info);
}
