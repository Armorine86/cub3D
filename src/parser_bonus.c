/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:40:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/10 10:08:05 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "config.h"
#include <libft/libft.h>
#include "parser.h"
#include "game.h"
#include "utils.h"

t_parser	*init_parser(void)
{
	t_parser	*d;

	d = ft_calloc(1, sizeof(t_parser));
	d->map = ft_calloc(1, sizeof(char *));
	d->tex = ft_calloc(1, sizeof(char *));
	return (d);
}

bool	read_file(t_parser *p, char *file)
{
	int		fd;
	int32_t	i;

	fd = open(file, O_RDWR);
	if (fd == -1)
		return (p_error("Error: Invalid File"));
	i = 0;
	if (!read_line(p, fd, 0, N_CONFIG) || !read_line(p, fd, 1, MAP_MAX_H))
		return (free_parser(p));
	if (!p->tex || !p->map)
		return (free_parser(p));
	if (!validate_data(p))
		return (free_parser(p));
	return (true);
}

void	world_setup(t_world *world, char **map)
{
	world->map = ft_strarr_dup(map);
	world->height = ft_strarr_size(map);
	world->width = find_longest_line(map);
	get_spawn_location(world->map, &world->spawn, &world->angle);
}

t_world	*create_world(void *mlx, char *file)
{
	t_parser	*p;
	t_world		*world;

	p = init_parser();
	world = ft_calloc(1, sizeof(t_world));
	if (read_file(p, file))
	{
		world_setup(world, p->map);
		load_texture(world, mlx, p->tex);
		free_parser(p);
	}
	else
	{
		free(world);
		return (NULL);
	}
	return (world);
}
