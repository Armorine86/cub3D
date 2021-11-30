/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:39:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/30 11:08:08 by mmondell         ###   ########.fr       */
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

int	verify_identifier(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3))
		return (1);
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (2);
	return (0);
}
