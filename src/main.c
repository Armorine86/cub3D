/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 23:58:38 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <libft/libft.h>
#include <stdint.h>
#include "draw.h"
#include "game.h"
#include "utils.h"
#include "keymap.h"

int	update(void *data)
{
	t_game	*game;

	game = data;
	update_player(&game->player, game->keystate, 1.0f);
	clear_buffer(game->buf, 0x777777);
	draw_grid(game->buf);
	draw_player(game->buf, &game->player);
	update_screen(game);
	return (0);
}

int	keydown(int key, void *data)
{
	t_game	*game;

	game = data;
	if (key == KEY_W)
		game->keystate[W] = true;
	else if (key == KEY_A)
		game->keystate[A] = true;
	else if (key == KEY_S)
		game->keystate[S] = true;
	else if (key == KEY_D)
		game->keystate[D] = true;
	return (0);
}

int	keyup(int key, void *data)
{
	t_game	*game;

	game = data;
	if (key == KEY_W)
		game->keystate[W] = false;
	else if (key == KEY_A)
		game->keystate[A] = false;
	else if (key == KEY_S)
		game->keystate[S] = false;
	else if (key == KEY_D)
		game->keystate[D] = false;
	return (0);
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_game		game;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "cub3D");
	game.player.dir = (t_vec2){0.0f, 1.0f};
	game.player.pos = (t_vec2){150.0f, 150.0f};
	game.buf = new_buffer(mlx, win, WIDTH, HEIGHT);
	mlx_do_key_autorepeatoff(mlx);
	mlx_hook(win, 2, 1 << 0, &keydown, &game);
	mlx_hook(win, 3, 1 << 1, &keyup, &game);
	mlx_loop_hook(mlx, &update, &game);
	mlx_loop(mlx);
}
