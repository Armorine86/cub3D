/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/01 14:04:04 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
# define MAP_INFO_H

# include <libft/libft.h>
# include "texture.h"

# define MAP_SYMBOL "01NSEW "
# define SPAWN "NSEW"
# define MAP_OOB ' '
# define MAP_EMPTY '0'
# define MAP_WALL '1'

typedef struct s_world
{
	t_texture	*tex[N_TEX];
	t_vec2		spawn;
	uint32_t	height;
	uint32_t	width;
	uint32_t	floor;
	uint32_t	ceiling;
	char		**map;
}	t_world;

#endif
