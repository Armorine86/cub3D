/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:39:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/01 13:52:15 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "parser.h"

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

bool	gnl_fail(t_parser *p, int32_t ret)
{
	if (ret == -1)
	{
		if (p->tex)
			ft_strarr_free(p->tex);
		if (p->rgb)
			ft_strarr_free(p->rgb);
		if (p->map)
			ft_strarr_free(p->map);
		return (true);
	}
	return (false);
}

t_ident	identifier_type(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3))
		return (ID_WALL);
	else if (!ft_strncmp(line, "F ", 2))
		return (ID_FLOOR);
	else if (!ft_strncmp(line, "C ", 2))
		return (ID_CEILING);
	return (ID_NONE);
}
