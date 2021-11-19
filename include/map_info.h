/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/19 08:36:23 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
# define MAP_INFO_H

# include "texture.h"

# define VALID_SYMBOL "01NSEW"

typedef struct s_world
{
	t_texture	*tex[N_TEXTURES];
	int			floor;
	int			ceiling;
	char		**map;
}	t_world;

//void	*free_map(t_world *map);
bool	valid_extension(char *file, char *ext);
bool	duplicate_identifier(char **info);
bool	missing_texture(char **tab);
char	**extract_texture_path(char *info);

#endif
