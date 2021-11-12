/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:32:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/12 09:32:55 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <mlx.h>
#include "game.h"

char	**extract_file_path(char *info)
{
	char	*temp;
	char	*start;
	char	*end;
	char	**tab;
	int		i;

	start = ft_strnstr(info, "EA", ft_strlen(info));
	end = ft_strnstr(info, ".cub", ft_strlen(start));
	while (start != end)
	{
		end++;
		i++;
	}
	while (*end)
		i++;
	temp = ft_substr(info, 0, i + 1);
	tab = ft_split(temp, '\n');
	free(temp);
	return (tab);
}

void	*free_texture(void *mlx, t_textures *t)
{
	if (mlx && t && t->img)
		mlx_destroy_image(mlx, t->img);
	free(t);
	return (NULL);
}

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
