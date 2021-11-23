/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:40:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/22 22:52:01 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include "game.h"

bool	valid_data(char **info, char *file)
{
	if (!valid_extension(file, ".cub"))
		return (false);
	if (!duplicate_identifier(info))
		return (false);
	return (true);
}

char	**read_file(t_world *world, char *file)
{
	char		**file_data;
	char		**map_info;
	int32_t		fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (NULL);
	}
	file_data = extract_file_data(fd);
	if (!file_data)
		return (NULL);
	map_info = get_map_layout(file_data);
	if (!valid_data(file_data, file) || !map_info)
	{
		ft_strarr_free(file_data);
		return (NULL);
	}
	world->map = map_info;
	return (file_data);
}

//void	get_floor_ceiling_colors(t_world *world, char **data)
//{
	
//}

void	create_map(t_game *game, char *file)
{
	char	**file_data;

	game->world = ft_calloc(1, sizeof(t_world));
	game->world->map = ft_calloc(1, sizeof(char *));
	file_data = read_file(game->world, file);
	if (!file_data || !game->world)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	load_texture(game->world, game->mlx, file_data);
	//get_floor_ceiling_colors(game->world, file_data);
	ft_strarr_free(file_data);
}
