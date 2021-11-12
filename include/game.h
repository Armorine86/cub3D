/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:50:54 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/12 09:48:07 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "buffer.h"
# include "player.h"
# include "map.h"

# define WIDTH 800
# define HEIGHT 600
# define SQUARE_SIZE 100
# define PAD_SIZE 3
# define N_TEXTURES 4


typedef struct s_game
{
	t_textures	*textures[N_TEXTURES];
	t_buffer	*buf;
	t_player	player;
	t_time		last_frame;
	t_map		*map;
	float		dt;
	bool		keystate[N_KEYS];
	void		*mlx;
	void		*win;
}	t_game;


void	init_game(t_game *game, void *mlx, void *win);
int		update(t_game *game);
int		quit_game(t_game *game);

#endif
