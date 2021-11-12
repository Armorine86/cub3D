/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:40:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/12 09:45:37 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include "game.h"

static t_textures	*store_texture(void *mlx, char *file)
{
	t_textures	*t;

	t = ft_calloc(1, sizeof(t_textures));
	if (!t)
		return (NULL);
	t->img = mlx_xpm_file_to_image(mlx, file, &t->width, &t->height);
	if (t->img)
		return(free_textures(mlx, t));
	t->data = mlx_get_data_addr(&t->img, &t->bpp, &t->pitch, &t->endian);
	t->file = file;
	return (t);
}

static t_textures	*get_textures_info(t_game *game, t_map *map)
{

}

static t_game	*textures_paths(t_game *game, char *info)
{
	char	**tex_path;
	int		n;

	n = 0;
	tex_path = extract_file_path(info);
	while (n < N_TEXTURES)
	{
		game->textures[n] = store_texture(game->mlx, tex_path[n + 1]);
		n += 2;
	}
	ft_strarr_free(tex_path);
	return(game);
}

static t_game	*get_map_data(t_game *game, const char *file)
{
	int		index;
	char	*save;
	char	*info;

	index = 0;
	game->map = ft_calloc(1, sizeof(t_map));
	info = read_to_str(file);
	save = info;
	game = textures_paths(&game->textures, info);
	free(save);
	return (game->map);
}

void	create_map(t_game *game, char *file)
{
	if (!valid_file_extension(file))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	game = get_map_data(game, file);
	if (!game->map)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (NULL);
	}
}
