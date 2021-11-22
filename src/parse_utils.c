/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:32:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/22 15:24:18 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mlx.h>

char	**get_map_layout(char **tab)
{
	int32_t	i;
	char	**map;

	map = ft_calloc(1, sizeof(char *));
	i = 6;
	while (tab[i])
	{
		map = ft_strarr_extend(map, tab[i]);
	}
	return (map);
}

bool	str_is_null(char *str)
{
	if (str[0] == '\0')
	{
		free(str);
		return (true);
	}
	return (false);
}

char	**extract_file_data(int fd)
{
	int32_t	ret;
	char	**infos;
	char	*line;

	infos = ft_calloc(1, sizeof(char *));
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			break ;
		if (str_is_null(line))
			continue ;
		infos = ft_strarr_extend(infos, line);
		free(line);
	}
	free(line);
	return (infos);
}
