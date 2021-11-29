/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/26 15:05:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
# define MAP_INFO_H

# include "texture.h"

typedef struct s_world
{
	t_texture	*tex[N_TEX];
	uint32_t	floor;
	uint32_t	ceiling;
	char		**map;
}	t_world;

char	**get_map_layout(t_world *world, char **tab);

#endif
