/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integrity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:03:16 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/15 14:51:32 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <libft/libft.h>
#include "world.h"
#include "parser.h"

static bool	check_right(char **map, int i, int j)
{
	while (map[i][j])
	{
		if (map[i][j] == MAP_WALL)
			return (true);
		if (map[i][j] == MAP_OOB)
			break ;
		j++;
	}
	return (p_index("Error: Map Is Open ", i, j));
}

static bool	check_left(char **map, int i, int j)
{
	while (map[i][j] && j >= 0)
	{
		if (map[i][j] == MAP_WALL)
			return (true);
		if (map[i][j] == MAP_OOB)
			break ;
		j--;
	}
	return (p_index("Error: Map Border is Open ", i, j + 1));
}

static bool	check_down(char **map, int i, int j)
{
	size_t	size;

	size = ft_strarr_size(map);
	while (map[i][j] && (size_t)i < size)
	{
		if (map[i][j] == MAP_WALL)
			return (true);
		if (map[i][j] == MAP_OOB)
			break ;
		i++;
	}
	return (p_index("Error: Map Is Open ", i - 1, j));
}

static bool	check_up(char **map, int i, int j)
{
	while (map[i][j] && i >= 0)
	{
		if (map[i][j] == MAP_WALL)
			return (true);
		if (map[i][j] == MAP_OOB || i < 1)
			break ;
		i--;
	}
	return (p_index("Error: Map Is Open ", i + 1, j));
}

bool	map_integrity(char **map)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_EMPTY)
			{
				if (!check_up(map, i, j))
					return (false);
				if (!check_down(map, i, j))
					return (false);
				if (!check_left(map, i, j))
					return (false);
				if (!check_right(map, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
