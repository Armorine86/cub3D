/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:50:54 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/12 15:14:06 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "buffer.h"
# include "player.h"
# include "map_info.h"
# include "textures.h"

# define WIDTH 800
# define HEIGHT 600
# define SQUARE_SIZE 100
# define PAD_SIZE 3

typedef struct s_game
{
	t_buffer	*buf;
	t_player	player;
	t_time		last_frame;
	t_world		*world;
	float		dt;
	bool		keystate[N_KEYS];
	void		*mlx;
	void		*win;
}	t_game;

t_game		*textures_paths(t_game *game, char *info);
void		init_game(t_game *game, void *mlx, void *win);
void		create_map(t_game *game, char *file);
int			update(t_game *game);
int			quit_game(t_game *game);

#endif
