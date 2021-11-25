/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:52:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/25 15:08:07 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdint.h>

# define MAP_SYMBOL "01NSEW "

typedef struct s_parser
{
	char	**tex;
	char	**rgb;
	char	**map;
}	t_parser;

int		p_error(char *msg);
bool	valid_file_ext(char *file, char *ext);
bool	valid_res(void);
bool	valid_map_line(char *line);
bool	map_closed(char **map);
bool	valid_rgb(char *str);
bool	valid_symbols(char *str);
bool	valid_identifier(char *str);
bool	duplicate_identifier(char **info);
bool	no_missing_texture(char **tab);
bool	missing_texture(char **tab);
bool	validate_data(t_parser *p);
void	sanitize_map(char **map);
void	free_parser(t_parser *p);
char	**read_line(char **data, int32_t fd, bool skip, int limit);



#endif
