/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:36:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/24 16:13:22 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "texture.h"
#include "config.h"
#include "libft/libft.h"
#include "parser.h"

bool	map_closed(char **map)
{
	int32_t	i;
	int32_t	j;
	int32_t	last;

	last = ft_strarr_size(map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0)
			{
				
			}
		}
	}
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
