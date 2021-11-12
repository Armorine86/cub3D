/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:58 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/12 09:46:10 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define VALID_SYMBOL "01NSEW"

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

void	create_map(t_game *game, char *file);
void	*free_map(t_map *map);
bool	valid_file_extension(char *file);
void	*free_texture(void *mlx, t_textures *t);
char	**extract_file_path(char *info);



#endif
