/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:32:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/11 10:10:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include "game.h"

void	*free_map(t_map *map)
{
	if (map->grid)
		ft_strarr_free(map->grid);
	if (map)
		free(map);
	return (NULL);
}

bool	valid_file_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if ((ft_strncmp(file + len - 4, ".cub", len)))
		return (false);
	return (true);
}
