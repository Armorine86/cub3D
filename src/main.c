/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/19 05:42:13 by mleblanc         ###   ########.fr       */
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
	t_game		game;

	if (argc != 2 || !valid_file_ext(argv[1], MAP_EXT))
	{
		p_error("Error: Invalid Map File");
		exit(EXIT_FAILURE);
	}
	ft_bzero(&game, sizeof(t_game));
	game.mlx = mlx_init();
	if (!game.mlx)
		return EXIT_FAILURE;
	game.world = create_world(game.mlx, argv[1]);
	if (!game.world)
		quit_game(&game);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "cub3D");
	init_game(&game);
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.win, KEY_PRESS, KEY_PRESS_MASK, &keydown, &game);
	mlx_hook(game.win, KEY_RELEASE, KEY_RELEASE_MASK, &keyup, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, NO_EVENT_MASK, &quit_game, &game);
	mlx_hook(game.win, MOTION_NOTIFY, POINTER_MOTION_MASK, &mouse_move, &game);
	mlx_loop_hook(game.mlx, &update, &game);
	mlx_loop(game.mlx);
}
