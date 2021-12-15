/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:36:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/15 12:57:50 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <stdlib.h>
#include "world.h"
#include "config.h"
#include "parser.h"


bool	is_all_digit(char **rgb)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (rgb[i][j] == '-')
				j++;
			if (!ft_isdigit(rgb[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	valid_rgb(char *str)
{
	int32_t	i;
	int32_t	num;
	char	**rgb;

	rgb = ft_split(str, ',');
	if (ft_strarr_size(rgb) < 3)
		return (p_error("Error: Missing RGB Value"));
	if (!is_all_digit(rgb))
	{
		ft_strarr_free(rgb);
		return (p_error("Error: RGB Values Are Not All Digits"));
	}
	i = 0;
	while (rgb[i])
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
		{
			ft_strarr_free(rgb);
			return (p_error("Error: RGB Value Outside Range [0, 255]"));
		}
		i++;
	}
	ft_strarr_free(rgb);
	return (true);
}

bool	valid_map_symbols(char **map)
{
	bool	spawn_found;
	int32_t	i;
	int32_t	j;

	spawn_found = false;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][0] == '\0')
				return (false);
			if (spawn_found && ft_strchr(SPAWN, map[i][j]))
				return (p_error("Error: Multiple Spawn Locations Found"));
			if (ft_strchr(SPAWN, map[i][j]))
				spawn_found = true;
			if (!ft_strchr(MAP_SYMBOL, map[i][j]))
				return (p_error("Error: Unrecognized Map Symbol"));
		}
	}
	if (!spawn_found)
		return (p_error("Error: Invalid Spawn Location"));
	return (true);
}

bool	valid_map(char **map)
{
	int32_t	i;
	int32_t	size;

	i = 0;
	size = ft_strarr_size(map);
	while (i < size - 1)
	{
		if (map[i][0] == '\0')
			return (false);
		i++;
	}
	return (true);
}

bool	validate_data(t_parser *p)
{
	if (!duplicate_identifier(p->tex) || !duplicate_identifier(p->rgb))
		return (p_error("Error: Duplicate Identifier Found"));
	if (!no_missing_texture(p->tex) || !no_missing_texture(p->rgb))
		return (p_error("Error: Texture Missing"));
	if (!valid_map(p->map))
		return (p_error("Error: Found Newline in Map"));
	if (!valid_map_symbols(p->map))
		return (false);
	if (!map_integrity(allocate_sqr_map(p->map)))
		return (false);
	return (true);
}
