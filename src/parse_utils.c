/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:32:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/11 14:22:06 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <mlx.h>
#include "game.h"

void	*free_texture(void *mlx, t_textures *t)
{
	if (mlx && t && t->img)
		mlx_destroy_image(mlx, t->img);
	free(t);
	return (NULL);
}

void	*free_map(t_map *map)
{
	if (map->grid)
		ft_strarr_free(map->grid);
	if (map)
		free(map);
	return (NULL);
}

bool	valid_file_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if ((ft_strncmp(file + len - 4, ".cub", len)))
		return (false);
	return (true);
}
