/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:50:54 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/07 15:25:01 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "buffer.h"
# include "player.h"
# include "world.h"
# include "mouse.h"

typedef struct s_game
{
	t_buffer	*buf3d;
	t_buffer	*minimap;
	t_player	player;
	t_time		last_frame;
	t_world		*world;
	bool		keystate[N_KEYS];
	t_mouse		mouse;
	bool		mouse_enabled;
	void		*mlx;
	void		*win;
	double		dt;
	t_texture	*wall;
}	t_game;

void	load_texture(t_world *world, void *mlx, char **info);
void	init_game(t_game *game);
void	update_screen(t_game *game);
int		quit_game(t_game *game);
int		update(t_game *game);

#endif
