/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:50:54 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/18 15:13:47 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "buffer.h"
# include "player.h"
# include "texture.h"

typedef struct s_game
{
	t_buffer	*buf;
	t_buffer	*buf3d;
	t_player	player;
	bool		keystate[N_KEYS];
	void		*mlx;
	void		*win;
	t_time		last_frame;
	double		dt;
	t_texture	*wall;
}	t_game;

void	init_game(t_game *game, void *mlx, void *win);
int		update(t_game *game);
int		quit_game(t_game *game);

#endif
