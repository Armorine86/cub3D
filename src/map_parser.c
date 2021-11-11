/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:40:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/11 10:29:26 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include "game.h"

t_map	*get_textures_info(t_map *map, char **str)
{
	int32_t	i;

	i = 0;
	while (map->info[i])
	{
		if (ft_strcmp(map->info[i], "NO"))
			
	}
}

static t_map	*get_data(t_map *map, const char *file)
{
	char	*temp;
	char	*grid;
	char	**tab;

	temp = read_to_str(file);
	map->info = ft_split(temp, '\n');
	free(temp);
	map = get_textures_info(map);
	free(str);
	map->grid = grid;
	return (map);
}

t_map	*create_map(t_map *map, char *file)
{
	if (!valid_file_extension(file))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	map = ft_calloc(1, sizeof(t_map));
	map = get_data(map, file);
	if (!map)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (NULL);
	}
	return (map);
}
