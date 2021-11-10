/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:57:40 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 00:12:42 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <mlx.h>

void	init_game(t_game *game, void *mlx, void *win)
{
	game->mlx = mlx;
	game->win = win;
	game->player.dir = (t_vec2){0.0f, 1.0f};
	game->player.pos = (t_vec2){150.0f, 150.0f};
	game->buf = new_buffer(mlx, win, WIDTH, HEIGHT);
	game->keystate[0] = false;
	game->keystate[1] = false;
	game->keystate[2] = false;
	game->keystate[3] = false;
}

void	update_screen(t_game *game)
{
	t_buffer	*buf;

	buf = game->buf;
	mlx_put_image_to_window(buf->mlx, buf->win, buf->img, 0, 0);
}

void	destroy_game(t_game *game)
{
	destroy_buffer(game->buf);
	mlx_destroy_window(game->mlx, game->win);
}
