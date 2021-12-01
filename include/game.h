/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:50:54 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/01 13:08:07 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "buffer.h"
# include "player.h"
# include "map_info.h"

typedef struct s_game
{
	t_buffer	*buf3d;
	t_player	player;
	t_time		last_frame;
	t_world		*world;
	bool		keystate[N_KEYS];
	void		*mlx;
	void		*win;
	double		dt;
	t_texture	*wall;
}	t_game;

t_world	*create_map(void *mlx, char *file);
void	load_texture(t_world *world, void *mlx, char **info);
void	init_game(t_game *game);
int		update(t_game *game);
int		quit_game(t_game *game);

#endif
