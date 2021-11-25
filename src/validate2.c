/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:36:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/25 14:20:27 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "texture.h"
#include "config.h"
#include "libft/libft.h"
#include "parser.h"

bool	valid_res(void)
{
	if ((long)HEIGHT > INT32_MAX || HEIGHT <= 0)
		return (p_error("Error: Invalid HEIGHT Resolution Value"));
	if ((long)WIDTH > INT32_MAX || WIDTH <= 0)
		return (p_error("Error: Invalid WIDTH Resolution Value"));
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

bool	map_closed(char **map)
{
	int32_t	i;
	int32_t	line_end;
	int32_t	last_row;

	i = 0;
	line_end = ft_strlen(map[i]);
	last_row = ft_strarr_size(map);
	while (map[i])
	{
		ft_putendl_fd(map[i], 1);
		if (i == 0 || i == last_row)
		{
			if (!top_bot_closed(map[i]))
				return (p_error("Error: Map is not Properly Closed"));
		}
		else if (map[i][0] != '1' || map[i][line_end] != '1')
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
