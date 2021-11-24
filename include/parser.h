/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:52:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/24 16:02:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define MAP_SYMBOL "01NSEW "

typedef struct s_parser
{
	char	**tex;
	char	**rgb;
	char	**map;
}	t_parser;

int		p_error(char *msg);
char	**read_line(char **data, int32_t fd, bool skip, int limit);
bool	valid_file_ext(char *file, char *ext);
bool	map_closed(char **map);
bool	valid_rgb(char *str);
bool	valid_symbols(char *str);
bool	valid_identifier(char *str);
bool	duplicate_identifier(char **info);
bool	missing_texture(char **tab);
bool	missing_texture(char **tab);
void	free_parser(t_parser *p);



#endif
