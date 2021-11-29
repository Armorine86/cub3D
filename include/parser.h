/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:52:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/29 12:20:54 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdint.h>

# define MAP_SYMBOL "01NSEW "
# define MAP_LIMIT 'X'

typedef struct s_parser
{
	char	**tex;
	char	**rgb;
	char	**map;
}	t_parser;

bool	p_error(char *msg);
bool	p_index(char *msg, int i, int j);
bool	valid_file_ext(char *file, char *ext);
bool	valid_res(void);
bool	map_closed(char **map);
bool	valid_rgb(char *str);
bool	valid_floor_ceiling(char *line);
bool	valid_map_symbols(char **map);
bool	valid_identifier(char *str);
bool	duplicate_identifier(char **info);
bool	no_missing_texture(char **tab);
bool	missing_texture(char **tab);
bool	validate_data(t_parser *p);
bool	map_integrity(char **map, char out_of_bound);
char	**sanitize_map(char **map);
bool	read_line(t_parser *p, int32_t fd, bool skip, int limit);
void	free_parser(t_parser *p);
//char	**read_line(char **data, int32_t fd, bool skip, int limit);

// UTILS
bool	str_is_null(char *str);
void	gnl_fail(t_parser *p, int32_t ret);
int		verify_identifier(char *line);



#endif
