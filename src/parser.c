/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:40:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/03 12:54:28 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "config.h"
#include <libft/libft.h>
#include "parser.h"
#include "game.h"
#include "utils.h"

void	get_colors(t_world *world, char **data)
{
	int32_t		i;
	uint32_t	color;
	char		**str;

	i = -1;
	while (++i < 2)
	{
		str = ft_split(data[i] + 1, ',');
		color = make_argb(0, ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
		if (!ft_strncmp(data[i], "F ", 2))
			world->floor = color;
		else
			world->ceiling = color;
		ft_strarr_free(str);
	}
}

t_parser	*init_parser(void)
{
	t_parser	*d;

	d = ft_calloc(1, sizeof(t_parser));
	d->map = ft_calloc(1, sizeof(char *));
	d->tex = ft_calloc(1, sizeof(char *));
	d->rgb = ft_calloc(1, sizeof(char *));
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
	if (!p->tex || !p->rgb || !p->map)
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
		get_colors(world, p->rgb);
		free_parser(p);
	}
	else
	{
		free(world);
		return (NULL);
	}
	return (world);
}
