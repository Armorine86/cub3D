/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:57:40 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/11 14:03:19 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

void	init_game(t_game *game, void *mlx, void *win)
{
	int	i;

	game->mlx = mlx;
	game->win = win;
	game->player.angle = deg_to_rad(90.0);
	game->player.dir.x = cos(game->player.angle);
	game->player.dir.y = sin(game->player.angle);
	game->player.pos = (t_vec2){3.5, 2.5};
	game->buf = new_buffer(mlx, win, WIDTH, HEIGHT);
	ft_gettime(&game->last_frame);
	game->dt = 0.0;
	i = 0;
	while (i < N_KEYS)
		game->keystate[i++] = false;
}

static void	update_screen(t_game *game)
{
	t_buffer	*buf;

	buf = game->buf;
	mlx_put_image_to_window(buf->mlx, buf->win, buf->img, 0, 0);
}

#ifdef COOL_EVALUATOR

int	update(t_game *game)
{
	t_time	t;

	ft_gettime(&t);
	game->dt = ft_timediff(game->last_frame, t);
	game->last_frame = t;
	update_player(&game->player, game->keystate, game->dt);
	clear_buffer(game->buf, 0x777777);
	draw_grid(game->buf);
	draw_player(game->buf, &game->player);
	update_screen(game);
	return (0);
}

#else

int	update(t_game *game)
{
	game->dt = 0.01f;
	update_player(&game->player, game->keystate, game->dt);
	clear_buffer(game->buf, 0x777777);
	draw_grid(game->buf);
	draw_player(game->buf, &game->player);
	update_screen(game);
	return (0);
}

#endif

int	quit_game(t_game *game)
{
	destroy_buffer(game->buf);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
