/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:36:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/29 13:21:18 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "texture.h"
#include "config.h"
#include "libft/libft.h"
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
			return (p_error("Error: RGB Value Outside Range"));
		}
		i++;
	}
	ft_strarr_free(rgb);
	return (true);
}

bool	valid_map_symbols(char **map)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(MAP_SYMBOL, map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	top_bot_closed(char *str)
{
	int32_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
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
	if (!valid_map_symbols(p->map))
		return (p_error("Error: Unrecognized Map Symbol"));
	p->map = sanitize_map(p->map);
	if (!map_integrity(p->map, MAP_LIMIT))
		return (false);
	return (true);
}
