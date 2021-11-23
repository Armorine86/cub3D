/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:32:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/23 09:44:40 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mlx.h>

int32_t	find_longest_line(char **tab)
{
	int32_t	len;
	int32_t	temp;
	int32_t	i;

	i = 0;
	len = 0;
	temp = 0;
	while (tab[i])
	{
		temp = ft_strlen(tab[i]);
		if (temp > len)
			len = temp;
		i++;
	}
	return (len);
}

char	**allocate_sqr_map(char **map, char **tab, int32_t size)
{
	int32_t	i;
	int32_t	j;
	int32_t	diff;
	char	*ptr;

	i = -1;
	while (tab[i++])
		map[i] = ft_calloc(size + 1, sizeof(char));
	i = 0;
	while (tab[i])
	{
		ptr = map[i];
		diff = size - ft_strlen(tab[i]);
		ft_memcpy(map[i], tab[i], size);
		j = size - diff;
		ptr += j;
		while (j < size)
		{
			*ptr = ' ';
			ptr++;
			j++;
		}	
		i++;
	}
	return (map);
}

char	**get_map_layout(char **tab)
{
	int32_t	size;
	char	**map;

	tab += 6;
	while (*tab[0] == '\0')
		tab++;
	size = ft_strarr_size(tab);
	map = ft_calloc(size + 1, sizeof(char *));
	size = find_longest_line(tab);
	return (allocate_sqr_map(map, tab, size));
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
		//free(line);
	}
	return (infos);
}
