/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:32:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/22 23:29:18 by mmondell         ###   ########.fr       */
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
	tab += 6;
	i = 0;
	while (*tab[0] == '\0')
		tab++;
	while (tab[i])
	{
		if (tab[i][0] == '\0')
		{
			ft_strarr_free(map);
			return (NULL);
		}
		map = ft_strarr_extend(map, tab[i]);
		i++;
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

char	**extract_file_data(int32_t fd)
{
	int32_t	ret;
	char	*temp;
	char	**infos;
	char	*line;

	infos = ft_calloc(1, sizeof(char *));
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret <= 0)
			break ;
		if (ft_strarr_size(infos) < 6)
		{
			if (str_is_null(line))
				continue ;
			temp = ft_strtrim(line, " ");
			infos = ft_strarr_extend(infos, temp);
		}
		else
			infos = ft_strarr_extend(infos, line);
		free(line);
	}
	return (infos);
}
