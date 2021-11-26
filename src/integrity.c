/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integrity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:03:16 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/26 12:00:59 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft/libft.h"
#include "parser.h"

static bool	check_right(char **map, int i, int j, char out_of_bound)
{
	while (map[i][j])
	{
		if (map[i][j] == '1')
			break ;
		if (map[i][j] == out_of_bound)
			return (p_index("Error: Map Is Open ", i, j));
		j++;
	}
	return (true);
}

static bool	check_left(char **map, int i, int j, char out_of_bound)
{
	while (map[i][j] && j > 0)
	{
		if (map[i][j] == '1')
			break ;
		if (map[i][j] == out_of_bound)
			return (p_index("Error: Map Border is Open ", i, j + 1));
		j--;
	}
	return (true);
}

static bool	check_down(char **map, int i, int j, char out_of_bound)
{
	while (map[i][j])
	{
		if (map[i][j] == '1')
			break ;
		if (map[i][j] == out_of_bound)
			return (p_index("Error: Map Is Open ", i - 1, j));
		i++;
	}
	return (true);
}

static bool	check_up(char **map, int i, int j, char out_of_bound)
{
	while (map[i][j] && i > 0)
	{
		if (map[i][j] == '1')
			break ;
		if (map[i][j] == out_of_bound)
			return (p_index("Error: Map Is Open ", i + 1, j));
		i--;
	}
	return (true);
}

bool	map_integrity(char **map, char out_of_bound)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (!check_up(map, i , j, out_of_bound))
					return (false);
				if (!check_down(map, i , j, out_of_bound))
					return (false);
				if (!check_left(map, i , j, out_of_bound))
					return (false);
				if (!check_right(map, i , j, out_of_bound))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
