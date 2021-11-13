/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:50:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/12 15:36:22 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include "game.h"

char	**extract_texture_path(char *info)
{
	char	*temp;
	char	*start;
	char	*end;
	char	**tab;
	size_t	i;

	i = 0;
	start = info;
	end = ft_strnstr(info, "EA", ft_strlen(info));
	if (!end)
		return (NULL);
	end = ft_strnstr(end, ".xpm", ft_strlen(info));
	while (start != end)
	{
		start++;
		i++;
	}
	i += 4;
	temp = ft_substr(info, 0, i);
	tab = ft_split(temp, '\n');
	free(temp);
	return (tab);
}

static t_textures	*store_texture(void *mlx, char *file)
{
	t_textures	*t;

	t = ft_calloc(1, sizeof(t_textures));
	if (!t)
		return (NULL);
	t->img = mlx_xpm_file_to_image(mlx, file, &t->width, &t->height);
	if (!t->img)
		return (free_texture(mlx, t));
	t->data = mlx_get_data_addr(&t->img, &t->bpp, &t->pitch, &t->endian);
	t->file = ft_strdup(file);
	return (t);
}

t_game	*textures_paths(t_game *game, char *info)
{
	char		**path;
	size_t		n;

	n = 0;
	path = extract_texture_path(info);
	if (!path)
		return (NULL);
	while (n < N_TEXTURES)
	{
		if (!(ft_strncmp(path[n], "NO", 2)))
			game->world->tex[NORTH] = store_texture(game->mlx, &path[n][3]);
		else if (!(ft_strncmp(path[n], "SO", 2)))
			game->world->tex[SOUTH] = store_texture(game->mlx, &path[n][3]);
		else if (!(ft_strncmp(path[n], "WE", 2)))
			game->world->tex[WEST] = store_texture(game->mlx, &path[n][3]);
		else if (!(ft_strncmp(path[n], "EA", 2)))
			game->world->tex[EAST] = store_texture(game->mlx, &path[n][3]);
		n++;
	}
	ft_strarr_free(path);
	return (game);
}
