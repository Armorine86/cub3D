/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:36:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/26 10:53:15 by mmondell         ###   ########.fr       */
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

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(MAP_SYMBOL, line[i]))
			return(false);
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
		return (false);
	if (!no_missing_texture(p->tex) || !no_missing_texture(p->rgb))
		return (false);
	if (!map_integrity(sanitize_map(p->map), MAP_LIMIT))
		return (false);
	return (true);
}
