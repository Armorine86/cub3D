/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:57:40 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 12:39:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <mlx.h>
#include <math.h>

void	init_game(t_game *game, void *mlx, void *win)
{
	int	i;

	game->mlx = mlx;
	game->win = win;
	game->player.angle = PI_F / 2.0f;
	game->player.dir.x = cosf(game->player.angle);
	game->player.dir.y = sinf(game->player.angle);
	game->player.pos = (t_vec2){350.0f, 250.0f};
	game->buf = new_buffer(mlx, win, WIDTH, HEIGHT);
	ft_gettime(&game->last_frame);
	game->dt = 0.0f;
	i = 0;
	while (i < N_KEYS)
	{
		game->keystate[i] = false;
		i++;
	}
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
