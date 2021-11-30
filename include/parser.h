/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:52:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/30 13:56:03 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdint.h>

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
bool	read_line(t_parser *p, int32_t fd, bool skip, int limit);
char	**allocate_sqr_map(char **map);

// UTILS
bool	str_is_null(char *str);
bool	gnl_fail(t_parser *p, int32_t ret);
int		verify_identifier(char *line);
char	**copy_arr(char **map);

#endif
