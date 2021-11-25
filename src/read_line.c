/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:29:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/25 15:34:36 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "parser.h"
#include "texture.h"
#include "config.h"

bool	valid_line(char **data, int32_t limit)
{
	char	*str;

	if (!data)
		return (false);
	str = ft_strarr_last(data);
	if (limit == N_TEX)
	{
		if (!valid_file_ext(str, ".xpm"))
			return (false);
		if (!valid_identifier(str))
			return (p_error("Error: Invalid Texture Identifier"));
	}
	else if (limit == N_COL)
	{
		if (!valid_identifier(str))
			return (p_error("Error: Invalid Floor/Ceiling Identifier"));
		if (!valid_rgb(str))
			return (p_error("Error: Invalid RGB Value"));
	}
	else if (limit == MAP_MAX_H)
	{
		if (!valid_map_symbols(str))
			return (p_error("Error: Invalid Map Symbols"));
	}
	return (true);
}

bool	str_is_null(char *str)
{
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (true);
	}
	return (false);
}

char	**gnl_fail(char **data, int32_t ret)
{
	if (ret == -1)
	{
		if (data)
			ft_strarr_free(data);
		return (NULL);
	}
	return (data);
}

char	**read_line(char **data, int32_t fd, bool skip, int limit)
{
	int32_t	ret;
	int32_t	dispatch;
	char	*line;

	ret = 1;
	dispatch = limit;
	while (ret && limit > 0)
	{
		ret = get_next_line(fd, &line);
		data = gnl_fail(data, ret);
		if (skip == false)
		{
			if (str_is_null(line))
				continue ;
			data = ft_strarr_extend(data, line);
			limit--;
		}
		else if (ft_strarr_size(data) == 0 && str_is_null(line))
			continue ;
		else if (data)
			data = ft_strarr_extend(data, line);
		if (!valid_line(data, dispatch))
			return (false);
	}
	return (data);
}
