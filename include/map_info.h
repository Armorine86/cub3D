/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/30 12:14:26 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
# define MAP_INFO_H

# include "texture.h"

# define MAP_SYMBOL "01NSEW "
# define MAP_OOB ' '
# define MAP_EMPTY '0'
# define MAP_WALL '1'

typedef struct s_world
{
	t_texture	*tex[N_TEX];
	uint32_t	floor;
	uint32_t	ceiling;
	char		**map;
}	t_world;

char	**get_map_layout(t_world *world, char **tab);

#endif
