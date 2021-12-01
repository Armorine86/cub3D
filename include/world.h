/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/01 15:24:36 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include <libft/libft.h>
# include "texture.h"

# define MAP_SYMBOL "01NSEW "
# define SPAWN "NSEW"
# define UP 'N'
# define DOWN 'S'
# define LEFT 'W'
# define RIGHT 'E'
# define MAP_OOB ' '
# define MAP_EMPTY '0'
# define MAP_WALL '1'

typedef struct s_world
{
	t_texture	*tex[N_TEX];
	t_vec2		spawn;
	double		angle;
	uint32_t	height;
	uint32_t	width;
	uint32_t	floor;
	uint32_t	ceiling;
	char		**map;
}	t_world;

t_world	*create_world(void *mlx, char *file);

#endif
