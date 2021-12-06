/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:57:40 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/06 14:49:27 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "config.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

void	init_game(t_game *game)
{
	int32_t		i;
	t_player	*p;

	p = &game->player;
	game->buf3d = new_buffer(game->mlx, WIDTH, HEIGHT);
	game->minimap = new_buffer(game->mlx, MM_WIDTH, MM_HEIGTH);
	p->fov_ratio = FOV / 90.0;
	p->angle = game->world->angle;
	p->dir.x = cos(p->angle);
	p->dir.y = sin(p->angle);
	p->pos = game->world->spawn;
	p->c_plane = ft_vec2_unit(p->angle + ft_deg_to_rad(90.0));
	p->c_plane = ft_vec2_mul(p->c_plane, p->fov_ratio);
	ft_gettime(&game->last_frame);
	game->dt = 0.0;
	i = 0;
	while (i < N_KEYS)
		game->keystate[i++] = false;
}

void	update_screen(t_game *game)
{
	t_buffer	*buf3d;
	t_buffer	*minimap;

	buf3d = game->buf3d;
	minimap = game->minimap;
	mlx_put_image_to_window(game->mlx, game->win, buf3d->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, minimap->img, 10, 10);
}

int	quit_game(t_game *game)
{
	int32_t	i;

	if (game->buf3d)
		destroy_buffer(game->mlx, game->buf3d);
	if (game->minimap)
		destroy_buffer(game->mlx, game->minimap);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	i = 0;
	if (game->world)
	{
		while (i < N_TEX)
			free_texture(game->mlx, game->world->tex[i++]);
		ft_strarr_free(game->world->map);
	}
	exit(0);
}
