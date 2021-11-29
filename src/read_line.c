/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:29:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/26 14:08:40 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "parser.h"
#include "texture.h"
#include "config.h"

bool	valid_line(t_parser *p, int32_t limit, char *line)
{
	if (!p->tex || !p->map)
		return (false);
	if (limit == N_TEX)
	{
		if (!valid_identifier(line))
			return (p_error("Error: Invalid Texture Identifier"));
		if (verify_identifier(line) == 1)
		{
			if (!valid_file_ext(line, ".xpm"))
				return (p_error("Error: Invalid Texture Extension"));
		}
	}
	else if (limit == MAP_MAX_H)
	{
		if (!valid_map_symbols(line))
			return (p_error("Error: Invalid Map Symbols"));
	}
	return (true);
}

void	dispatch_line(t_parser *p, char *line)
{
	if (verify_identifier(line) == 1)
		p->tex = ft_strarr_extend(p->tex, line);
	else if (verify_identifier(line) == 2)
		p->rgb = ft_strarr_extend(p->rgb, line);
}

bool	read_line(t_parser *p, int32_t fd, bool skip, int limit)
{
	int32_t	ret;
	int32_t	dispatch;
	char	*line;

	ret = 1;
	dispatch = limit;
	while (ret && limit > 0)
	{
		ret = get_next_line(fd, &line);
		gnl_fail(p, ret);
		if (skip == false)
		{
			if (str_is_null(line))
				continue ;
			if (!valid_line(p, dispatch, line))
				return (false);
			dispatch_line(p, line);
			limit--;
		}
		else if (ft_strarr_size(p->map) == 0 && str_is_null(line))
			continue ;
		else
			p->map = ft_strarr_extend(p->map, line);
	}
	return (true);
}
