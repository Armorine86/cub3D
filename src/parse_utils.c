/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:32:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/29 14:37:29 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mlx.h>
#include "libft/libft.h"
#include "map_info.h"
#include "parser.h"

char	**copy_arr(char **map)
{
	int32_t	i;
	int32_t	size;
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

void	free_parser(t_parser *p)
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
}

int32_t	find_longest_line(char **map)
{
	int32_t	len;
	int32_t	temp;
	int32_t	i;

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
	int32_t		size;

	size = find_longest_line(map);
	i = 0;
	while (map[i])
	{
		diff = size - ft_strlen(map[i]);
		str = ft_str_new_copy(map[i]);
		while (diff-- > 0)
			ft_str_add_back(str, MAP_LIMIT);
		free(map[i]);
		map[i] = ft_str_take(str);
		i++;
	}
	return (map);
}

char	**sanitize_map(char **map)
{
	int32_t	i;
	int32_t	j;

	allocate_sqr_map(map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = 'X';
			j++;
		}
		i++;
	}
	return (map);
}
