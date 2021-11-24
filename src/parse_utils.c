/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:32:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/24 14:39:56 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mlx.h>
#include "map_info.h"
#include "parser.h"

void	free_parser(t_parser *p)
{
	if (p)
	{
		if (p->map)
			ft_strarr_free(p->map);
		if (p->tex)
			ft_strarr_free(p->tex);
		if (p->rgb)
			ft_strarr_free(p->rgb);
		free(p);
	}
}

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

char	**allocate_sqr_map(t_world *world, char **tab, int32_t size)
{
	t_string	str;
	int32_t		i;
	int32_t		diff;

	i = 0;
	while (tab[i])
	{
		diff = size - ft_strlen(tab[i]);
		str = ft_str_new_copy(tab[i]);
		while (diff-- > 0)
			ft_str_add_back(str, ' ');
		world->map[i] = ft_str_take(str);
		i++;
	}
	return (world->map);
}

char	**get_map_layout(t_world *world, char **tab)
{
	int32_t	size;
	//char	**map;
	tab += 6;
	while (*tab[0] == '\0')
		tab++;
	size = ft_strarr_size(tab);
	world->map = ft_calloc(size + 1, sizeof(char *));
	size = find_longest_line(tab);
	return (allocate_sqr_map(world, tab, size));
}
