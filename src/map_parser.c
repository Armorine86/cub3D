/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:40:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/12 15:44:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include "game.h"

bool	valid_file(char *info, char *file)
{
	if (!valid_file_extension(file))
		return (false);
	if (!duplicate_identifier(info))
		return (false);
	return (true);
}

static t_game	*get_map_data(t_game *game, char *info)
{
	int		index;

	index = 0;
	game->world = ft_calloc(1, sizeof(t_world));
	if (!game->world)
		return (NULL);
	game = textures_paths(game, info);
	return (game);
}

void	create_map(t_game *game, char *file)
{
	char	*info;

	info = read_to_str(file);
	if (!valid_file(info, file))
	{
		ft_putendl_fd("Error\n", 2);
		exit(EXIT_FAILURE); //TODO FREE Function
	}
	game = get_map_data(game, info);
	free(info);
	if (!game->world)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
