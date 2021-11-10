/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 16:42:15 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <libft/libft.h>
#include <stdint.h>
#include <stdlib.h>
#include "draw.h"
#include "game.h"
#include "utils.h"
#include "keymap.h"

int	update(void *data)
{
	t_game	*game;
	t_time	t;

	game = data;
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

int	keydown(int key, t_game *game)
{
	if (key == KEY_W)
		game->keystate[W] = true;
	else if (key == KEY_A)
		game->keystate[A] = true;
	else if (key == KEY_S)
		game->keystate[S] = true;
	else if (key == KEY_D)
		game->keystate[D] = true;
	else if (key == KEY_LEFT)
		game->keystate[LEFT] = true;
	else if (key == KEY_RIGHT)
		game->keystate[RIGHT] = true;
	else if (key == KEY_ESC)
	{
		destroy_game(game);
		exit(0);
	}
	return (0);
}

int	keyup(int key, t_game *game)
{
	if (key == KEY_W)
		game->keystate[W] = false;
	else if (key == KEY_A)
		game->keystate[A] = false;
	else if (key == KEY_S)
		game->keystate[S] = false;
	else if (key == KEY_D)
		game->keystate[D] = false;
	else if (key == KEY_LEFT)
		game->keystate[LEFT] = false;
	else if (key == KEY_RIGHT)
		game->keystate[RIGHT] = false;
	return (0);
}

int	quit_game(t_game *game)
{
	destroy_game(game);
	exit(0);
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_game		game;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "cub3D");
	init_game(&game, mlx, win);
	mlx_do_key_autorepeatoff(mlx);
	mlx_hook(win, 2, 1, &keydown, &game);
	mlx_hook(win, 3, 2, &keyup, &game);
	mlx_hook(win, 17, 0, &quit_game, &game);
	mlx_loop_hook(mlx, &update, &game);
	mlx_loop(mlx);
}
