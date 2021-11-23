/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/23 12:29:15 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
# define MAP_INFO_H

# include "texture.h"

# define MAP_SYMBOL "01NSEW"

typedef struct s_world
{
	t_texture	*tex[N_TEXTURES];
	int			floor[3];
	int			ceiling[3];
	char		**map;
}	t_world;

bool	valid_extension(char *file, char *ext);
bool	duplicate_identifier(char **info);
bool	missing_texture(char **tab);
char	**extract_file_data(int32_t fd);
char	**get_map_layout(t_world *world, char **tab);

#endif
