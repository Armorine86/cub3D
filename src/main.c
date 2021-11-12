/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/12 09:48:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "event.h"
#include "fixed_map.h"

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	t_game		game;
	

	if (argc != 2)
	{
		ft_putendl_fd("Error: Enter a valid map", 2);
		exit(EXIT_FAILURE);
	}
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
