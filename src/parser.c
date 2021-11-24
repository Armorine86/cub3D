/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:40:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/24 16:02:02 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "config.h"
#include "libft/libft.h"
#include "parser.h"
#include "game.h"

// void	get_floor_ceiling_colors(t_world *world, char **data)
// {
// 	int32_t	i;
// 	char	*ptr;
// 	char	**floor;
// 	char	**ceiling;

// 	data += 4;
// 	i = -1;
// 	while (++i < 2)
// 	{
// 		ptr = data[i];
// 		if (*ptr == 'F')
// 		{
// 			ptr++;
// 			floor = ft_split(ptr, ',');
// 		}
// 		else if (*ptr == 'C')
// 		{
// 			ptr++;
// 			ceiling = ft_split(ptr, ',');
// 		}
// 	}
// 	load_colors(world, floor, ceiling);
// 	ft_strarr_free(floor);
// 	ft_strarr_free(ceiling);
// }

// void	load_colors(t_world *world, char **floor, char **ceiling)
// {
// 	int32_t	i;

// 	i = -1;
// 	while (++i < 3)
// 	{
// 		world->floor[i] = ft_atoi(floor[i]);
// 		world->ceiling[i] = ft_atoi(ceiling[i]);
// 	}
// }

t_parser	*init_parser(void)
{
	t_parser	*d;

	d = ft_calloc(1, sizeof(t_parser));
	d->map = ft_calloc(1, sizeof(char *));
	d->tex = ft_calloc(1, sizeof(char *));
	d->rgb = ft_calloc(1, sizeof(char *));
	return (d);
}

char	**sanitize_map(char **map)
{
	char	**sanitized_map;
	int32_t	size;
	int32_t	first;
	int32_t	i;

	first = 0;
	size = 0;
	while (**map == '\0')
	{
		map++;
		first++;
	}
	size = ft_strarr_size(map);
	sanitized_map = ft_calloc(size + 1, sizeof(char *));
	i = 0;
	while (map[i])
		sanitized_map[i] = ft_strdup(map[i]);
	map -= first;
	ft_strarr_free(map);
	return (sanitized_map);
}

bool	read_file(char *file)
{
	t_parser	*p;
	int32_t		fd;

	p = init_parser();
	fd = open(file, O_RDWR);
	if (fd == -1)
		return (p_error("Error: Invalid File Descriptor"));
	p->tex = read_line(p->tex, fd, 0, N_TEX);
	p->rgb = read_line(p->rgb, fd, 0, N_COL);
	p->map = read_line(p->map, fd, 1, MAP_MAX_H);
	if (!p->tex || !p->rgb || !p->map)
	{
		free_parser(p);
		return (p_error("Error: File Read Failed"));
	}
	if (duplicate_identifier(p->tex) || !map_closed(p->map))
		return (false);
	return (true);
}

void	create_map(t_game *game, char *file)
{
	game->world = ft_calloc(1, sizeof(t_world));
	if (read_file(file))
	{
		// load_texture(game->world, game->mlx, file_data);
		// get_floor_ceiling_colors(game->world, file_data);
		// ft_strarr_free(file_data);
	}
	else
		quit_game(game);
}
