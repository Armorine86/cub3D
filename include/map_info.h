/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/24 14:21:34 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
# define MAP_INFO_H

# include "texture.h"

typedef struct s_world
{
	t_texture	*tex[N_TEX];
	int			floor[3];
	int			ceiling[3];
	char		**map;
}	t_world;

char	**get_map_layout(t_world *world, char **tab);

#endif
