/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:36:26 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/10 14:12:05 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <stdlib.h>
#include "world.h"
#include "config.h"
#include "parser.h"

bool	is_all_digit(char *rgb)
{
	int32_t	i;

	i = 0;
	while (rgb[i])
	{
		if (!ft_isdigit(rgb[i]))
			return (false);
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
	{
		ft_strarr_free(rgb);
		return (p_error("Error: Missing RGB Value"));
	}
	i = -1;
	while (rgb[++i])
	{
		num = ft_atoi(rgb[i]);
		if (!is_all_digit(rgb[i]) || (num < 0 || num > 255))
		{
			ft_strarr_free(rgb);
			return (p_error("Error: Invalid RGB Values"));
		}
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
				return (p_index("Error: Unrecognized Map Symbol", i, j));
		}
	}
	if (!spawn_found)
		return (p_error("Error: No Spawn Location Found"));
	return (true);
}

bool	valid_map(char **map)
{
	int32_t	i;
	int32_t	size;
	bool	valid;

	valid = true;
	i = 0;
	size = ft_strarr_size(map);
	while (i < size - 1)
	{
		if (valid && map[i][0] == '\0')
			valid = false;
		if (!valid && map[i][0] != '\0')
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
