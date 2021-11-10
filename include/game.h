/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:50:54 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 10:09:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "buffer.h"
# include "player.h"

# define WIDTH 800
# define HEIGHT 600
# define SQUARE_SIZE 100
# define PAD_SIZE 3

typedef struct s_game
{
	t_buffer	*buf;
	t_player	player;
	bool		keystate[4];
	void		*mlx;
	void		*win;
}	t_game;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

t_map	*create_map(char *file);
t_map 	*parse_file(char *file);
void	init_game(t_game *game, void *mlx, void *win);
void	update_screen(t_game *game);
void	destroy_game(t_game *game);

/* PARSE UTILS */

bool	valid_extension(char *file);

#endif
