/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:40:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/10 14:59:11 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include "game.h"

void	*free_map(t_map *map)
{
	if (map->grid)
		ft_strarr_free(map->grid);
	if (map)
		free(map);
	return (NULL);
}

static t_map	*new_map(char *file)
{
	t_map	*map;
	ssize_t	lines;

	lines = count_lines(file);
	if (lines < 1)
		return (NULL);
	map = ft_calloc(1, sizeof (t_map));
	if (!map)
		return (NULL);
	map->height = (int32_t)lines;
	map->grid = (char **)ft_calloc((size_t)lines + 1, sizeof(char *));
	if (!map->grid)
		return (NULL);
	return (map);
}

static t_map	*parse_map(char *file)
{
	char		*str;
	char		**tab;
	t_map		*map;
	int32_t		ret;
	int32_t		fd;

	map = new_map(file);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free_map(map));
	ret = 1;
	str = read_to_str(file);
	tab = ft_split(str, '\n');
	free(str);
	map->grid = tab;
	return (map);
}

t_map	*create_map(char *file)
{
	t_map	*map;

	if (!valid_extension(file))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (NULL);
	}
	map = parse_map(file);
	if (!map)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (NULL);
	}
	return (map);
}
