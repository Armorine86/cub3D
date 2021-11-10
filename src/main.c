/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 10:58:50 by mmondell         ###   ########.fr       */
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

	game = data;
	update_player(&game->player, game->keystate, 1.0f);
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
	return (0);
}

int	quit_game(t_game *game)
{
	destroy_game(game);
	exit(0);
}

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		*map;

	if (argc != 2)
	{
		ft_putendl_fd("Error: Enter a valid map", 2);
		exit(EXIT_FAILURE);
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "cub3D");
	init_game(&game, mlx, win);
	map = create_map(argv[1]);
	for (int i = 0; i < map->height; i++)
		printf("%s\n", map->grid[i]);
	mlx_do_key_autorepeatoff(mlx);
	mlx_hook(win, 2, 1, &keydown, &game);
	mlx_hook(win, 3, 2, &keyup, &game);
	mlx_hook(win, 17, 0, &quit_game, &game);
	mlx_loop_hook(mlx, &update, &game);
	read_to_str()
	mlx_loop(mlx);
}
