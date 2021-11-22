/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/22 14:05:56 by mmondell         ###   ########.fr       */
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

bool	valid_extension(char *file, char *ext);
bool	duplicate_identifier(char **info);
bool	missing_texture(char **tab);
char	**extract_file_data(int fd);
char	**get_map_layout(char **tab);

#endif
