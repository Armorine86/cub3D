/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/11 10:48:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define N_TEXTURES 4

typedef enum e_pos
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
}	t_pos;

typedef struct s_textures
{
	void	*img;
	char	*file;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		pitch;
	int		endian;
}	t_textures;


typedef struct s_map
{
	char		**info;
	char		**grid;
	int			width;
	int			height;
}	t_map;

t_map	*create_map(t_map *map, char *file);
void	*free_map(t_map *map);
bool	valid_file_extension(char *file);

#endif
