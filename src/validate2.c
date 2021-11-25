/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:36:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/25 15:35:21 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "texture.h"
#include "config.h"
#include "libft/libft.h"
#include "parser.h"

bool	valid_map_symbols(char *line)
{
	int32_t	i;
	int32_t	line_end;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(MAP_SYMBOL, line[i]))
			return(false);
		i++;
	}
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

bool	map_closed(char **map)
{
	int32_t	i;
	int32_t	last_row;

	i = 0;
	last_row = ft_strarr_size(map) - 1;
	while (map[i])
	{
		if (i == 0 || i == last_row)
		{
			if (!top_bot_closed(map[i]))
				return (p_error("Error: Map is not Properly Closed"));
		}
		else if (!valid_map_line(map[i]))
			return (p_error("Error: Map is not Properly Closed"));
		i++;
	}
	return (true);
}

bool	valid_symbols(char *str)
{
	int32_t	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_strchr(MAP_SYMBOL, str[i]))
			return (false);
	}	
	return (true);
}

bool	validate_data(t_parser *p)
{
	
	if (!duplicate_identifier(p->tex) || !duplicate_identifier(p->rgb))
		return (false);
	if (!no_missing_texture(p->tex) || !no_missing_texture(p->rgb))
		return (false);
	if (!map_closed(p->map))
		return (false);
	return (true);
}
