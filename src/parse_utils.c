/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:32:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/01 14:20:24 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mlx.h>
#include "libft/libft.h"
#include "map_info.h"
#include "parser.h"

t_vec2	find_spawn_location(char **map)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr(SPAWN, map[y][x]))
			{
				map[y][x] = MAP_EMPTY;
				return ((t_vec2){(double)x + 0.5, (double)y + 0.5});
			}
			x++;
		}
		y++;
	}
	return ((t_vec2){0, 0});
}

char	**copy_arr(char **map)
{
	int32_t	i;
	size_t	size;
	char	**new_map;

	size = ft_strarr_size(map);
	new_map = ft_calloc(size + 1, sizeof(char *));
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	return (new_map);
}

bool	free_parser(t_parser *p)
{
	if (p)
	{
		if (p->map)
			ft_strarr_free(p->map);
		if (p->tex)
			ft_strarr_free(p->tex);
		if (p->rgb)
			ft_strarr_free(p->rgb);
		free(p);
	}
	return (false);
}

size_t	find_longest_line(char **map)
{
	size_t	len;
	size_t	temp;
	size_t	i;

	i = 0;
	len = 0;
	temp = 0;
	while (map[i])
	{
		temp = ft_strlen(map[i]);
		if (temp > len)
			len = temp;
		i++;
	}
	return (len);
}

char	**allocate_sqr_map(char **map)
{
	t_string	str;
	int32_t		i;
	int32_t		diff;
	uint32_t	size;

	size = find_longest_line(map);
	i = 0;
	while (map[i])
	{
		diff = size - ft_strlen(map[i]);
		str = ft_str_new_copy(map[i]);
		while (diff-- > 0)
			ft_str_add_back(str, MAP_OOB);
		free(map[i]);
		map[i] = ft_str_take(str);
		i++;
	}
	return (map);
}
