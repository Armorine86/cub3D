/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/30 14:51:08 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "event.h"
#include "parser.h"
#include "game.h"
#include "config.h"

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	t_game		game;

	if (argc != 2 || !valid_file_ext(argv[1], MAP_EXT))
		exit(EXIT_FAILURE);
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "cub3D");
	init_game(&game, mlx, win);
	create_map(&game, argv[1]);
	mlx_do_key_autorepeatoff(mlx);
	mlx_hook(win, KEY_PRESS, KEY_PRESS_MASK, &keydown, &game);
	mlx_hook(win, KEY_RELEASE, KEY_RELEASE_MASK, &keyup, &game);
	mlx_hook(win, DESTROY_NOTIFY, NO_EVENT_MASK, &quit_game, &game);
	mlx_loop_hook(mlx, &update, &game);
	mlx_loop(mlx);
}
