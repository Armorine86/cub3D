/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:29:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/15 15:25:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <libft/libft.h>
#include "parser.h"
#include "texture.h"
#include "config.h"

bool	valid_path(char *line)
{
	int32_t	fd;
	char	*file;

	if (identifier_type(line) == ID_WALL)
		file = ft_strtrim(line + 2, " ");
	else
		file = ft_strtrim(line, " ");
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		free(file);
		return (p_error("Error: Invalid Texture Path"));
	}
	close(fd);
	free(file);
	return (true);
}

bool	valid_line(char *line)
{
	t_ident	type;

	if (valid_identifier(line))
	{
		type = identifier_type(line);
		if (type == ID_CEILING || type == ID_FLOOR)
			return (valid_floor_ceiling(line));
		if (type == ID_WALL)
		{
			if (valid_file_ext(line, TEX_EXT) && valid_path(line))
				return (true);
			free(line);
			return (false);
		}
	}
	free(line);
	return (false);
}

bool	read_line(t_parser *p, int fd, bool skip, int limit)
{
	int32_t	ret;
	char	*line;

	ret = 1;
	while (ret && limit > 0)
	{
		ret = ft_get_next_line(fd, &line);
		if (ret == -1)
			return (p_error("Error: File Read Failed"));
		if (skip == false)
		{
			if (str_is_empty(line))
				continue ;
			if (!valid_line(line))
				return (false);
			p->tex = ft_strarr_extend(p->tex, line);
			limit--;
		}
		else if (ft_strarr_size(p->map) == 0 && str_is_empty(line))
			continue ;
		else
			p->map = ft_strarr_extend(p->map, line);
	}
	return (true);
}
