/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:40:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/18 14:45:50 by mmondell         ###   ########.fr       */
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

static t_world	*get_map_data(void *mlx, char **info)
{
	t_world	*world;

	world = ft_calloc(1, sizeof(t_world));
	if (!world)
		return (NULL);
	load_texture(world, mlx, info);
	return(world);	
}

void	create_map(t_game *game, char *file)
{
	char	**tex_data;
	int		fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	tex_data = extract_tex_data(fd);
	if (!valid_data(tex_data, file))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE); //TODO FREE Function
	}
	game->world = get_map_data(game->mlx, tex_data);
	ft_strarr_free(tex_data);
	if (!game->world)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
