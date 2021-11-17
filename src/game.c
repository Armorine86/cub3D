/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:57:40 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/17 01:44:22 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "fixed_map.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

void	init_game(t_game *game, void *mlx, void *win)
{
	int	i;

	game->mlx = mlx;
	game->win = win;
	game->player.angle = deg_to_rad(0.0);
	game->player.dir.x = cos(game->player.angle);
	game->player.dir.y = sin(game->player.angle);
	game->player.pos = (t_vec2){2.5, 1.5};
	game->player.c_plane.x = 0.66 * cos(game->player.angle - PI / 2.0);
	game->player.c_plane.y = 0.66 * sin(game->player.angle - PI / 2.0);
	game->buf = new_buffer(mlx, win, WIDTH / 2, HEIGHT);
	game->buf3d = new_buffer(mlx, win, WIDTH / 2, HEIGHT);
	ft_gettime(&game->last_frame);
	game->dt = 0.0;
	i = 0;
	while (i < N_KEYS)
		game->keystate[i++] = false;
}

static void	update_screen(t_game *game)
{
	t_buffer	*buf;
	t_buffer	*buf3d;

	buf = game->buf;
	buf3d = game->buf3d;
	mlx_put_image_to_window(buf->mlx, buf->win, buf->img, 0, 0);
	mlx_put_image_to_window(buf->mlx, buf->win, buf3d->img, WIDTH / 2, 0);
}

int	update(t_game *game)
{
	t_time	t;

	ft_gettime(&t);
	game->dt = ft_timediff(game->last_frame, t);
	game->last_frame = t;
	update_player(&game->player, game->keystate, game->dt);
	clear_buffer(game->buf, 0x777777);
	clear_buffer(game->buf3d, 0x777777);
	draw_grid(game->buf);
	draw_field(game->buf, &game->player, 0xFF00);
	draw_player(game->buf, &game->player);
	draw_view(game->buf3d, &game->player);
	update_screen(game);
	return (0);
}

int	quit_game(t_game *game)
{
	destroy_buffer(game->buf);
	destroy_buffer(game->buf3d);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
