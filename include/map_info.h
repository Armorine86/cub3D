/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/12 15:15:37 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
# define MAP_INFO_H

# include "textures.h"

# define VALID_SYMBOL "01NSEW"

typedef struct s_world
{
	t_textures	*tex[N_TEXTURES];
	int			*floor[3];
	int			*ceiling[3];
	char		**map;
}	t_world;

//void	*free_map(t_world *map);
void	*free_texture(void *mlx, t_textures *t);
bool	valid_file_extension(char *file);
bool	duplicate_identifier(char *info);
bool	missing_texture(char **tab);
char	**extract_texture_path(char *info);

#endif
