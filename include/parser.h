/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:52:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/15 15:31:06 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdint.h>
# define TEX_EXT ".xpm"
# define MAP_EXT ".cub"

# ifndef MAP_SYMBOL
#  define MAP_SYMBOL "01NSEW "
# endif

typedef struct s_parser
{
	char	**tex;
	char	**rgb;
	char	**map;
}	t_parser;

typedef enum e_ident
{
	ID_NONE,
	ID_WALL,
	ID_FLOOR,
	ID_CEILING
}	t_ident;

bool	p_error(char *msg);
bool	p_index(char *msg, int i, int j);
bool	valid_file_ext(char *file, char *ext);
bool	valid_res(void);
bool	map_closed(char **map);
bool	valid_rgb(char *str);
bool	valid_path(char *line);
bool	valid_floor_ceiling(char *line);
bool	valid_map_symbols(char **map);
bool	valid_identifier(char *str);
bool	duplicate_identifier(char **info);
bool	no_missing_texture(char **tab);
bool	missing_texture(char **tab);
bool	validate_data(t_parser *p);
bool	map_integrity(char **map);
bool	free_parser(t_parser *p);
bool	read_line(t_parser *p, int fd, bool skip, int limit);
char	**allocate_sqr_map(char **map);

// UTILS

bool	str_is_empty(char *str);
bool	gnl_fail(t_parser *p, int32_t ret);
t_ident	identifier_type(char *line);
char	**copy_arr(char **map);
size_t	find_longest_line(char **map);
void	get_spawn_location(char **map, t_vec2 *spawn, double *angle);

#endif
