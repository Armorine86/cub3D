/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:50:54 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/11 01:14:41 by mleblanc         ###   ########.fr       */
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
	bool		keystate[N_KEYS];
	void		*mlx;
	void		*win;
	t_time		last_frame;
	float		dt;
}	t_game;

void	init_game(t_game *game, void *mlx, void *win);
int		update(t_game *game);
int		quit_game(t_game *game);

#endif
