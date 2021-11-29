/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:40:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/29 13:27:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "config.h"
#include "libft/libft.h"
#include "parser.h"
#include "game.h"
#include "utils.h"

uint32_t	get_colors(char *data)
{
	uint32_t	color;
	char		*new_data;
	char		**str;

	data++;
	new_data = ft_strtrim(data, " ");
	str = ft_split(new_data, ',');
	color = make_argb(0, ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
	ft_strarr_free(str);
	free(new_data);
	return (color);
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
	int32_t		fd;
	int32_t		i;

	fd = open(file, O_RDWR);
	if (fd == -1)
		return (p_error("Error: Invalid File Descriptor"));
	i = 0;
	if (!read_line(p, fd, 0, N_CONFIG) || !read_line(p, fd, 1, MAP_MAX_H))
		return (false);
	if (!p->tex || !p->rgb || !p->map)
	{
		free_parser(p);
		return (p_error("Error: File Read Failed"));
	}
	if (!validate_data(p))
	{
		free_parser(p);
		return (false);
	}
	return (true);
}

void	create_map(t_game *game, char *file)
{
	int32_t		i;
	t_parser	*p;

	p = init_parser();
	game->world = ft_calloc(1, sizeof(t_world));
	if (read_file(p, file))
	{
		game->world->map = p->map;
		load_texture(game->world, game->mlx, p->tex);
		if (N_TEX == 4)
		{
			i = -1;
			while (++i < 2)
			{
				if (!ft_strncmp(p->rgb[i], "F ", 2))
					game->world->floor = get_colors(p->rgb[0]);
				else
					game->world->ceiling = get_colors(p->rgb[1]);
			}
		}
	}
	else
	{
		free_parser(p);
		quit_game(game);
	}
}
