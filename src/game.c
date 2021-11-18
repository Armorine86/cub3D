/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:57:40 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/18 15:22:12 by mleblanc         ###   ########.fr       */
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
	int32_t		i;
	t_player	*p;

	p = &game->player;
	game->mlx = mlx;
	game->win = win;
	p->fov_ratio = FOV / 90.0;
	p->angle = deg_to_rad(0.0);
	p->dir.x = cos(p->angle);
	p->dir.y = sin(p->angle);
	p->pos = (t_vec2){2.5, 1.5};
	p->c_plane = vec2_unit(p->angle + deg_to_rad(90.0));
	p->c_plane = vec2_mul(p->c_plane, p->fov_ratio);
	game->buf = new_buffer(mlx, WIDTH / 2, HEIGHT);
	game->buf3d = new_buffer(mlx, WIDTH / 2, HEIGHT);
	game->wall = new_texture(mlx, "textures/wall.xpm");
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
	mlx_put_image_to_window(game->mlx, game->win, buf->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, buf3d->img, WIDTH / 2, 0);
}

int	update(t_game *game)
{
	t_time	t;
	int32_t	w;
	int32_t	h;

	ft_gettime(&t);
	game->dt = ft_timediff(game->last_frame, t);
	game->last_frame = t;
	update_player(&game->player, game->keystate, game->dt);
	clear_buffer(game->buf, 0x777777);
	w = game->buf3d->w;
	h = game->buf3d->h;
	draw_rect(game->buf3d, (t_vec2){0, 0}, (t_vec2){w, h / 2}, 0xFFFF);
	draw_rect(game->buf3d, (t_vec2){0, h / 2}, (t_vec2){w, h}, 0x777777);
	draw_grid(game->buf);
	draw_field(game->buf, &game->player, 0xFF00);
	draw_player(game->buf, &game->player);
	draw_view(game->buf3d, &game->player);
	update_screen(game);
	return (0);
}

int	quit_game(t_game *game)
{
	destroy_buffer(game->mlx, game->buf);
	destroy_buffer(game->mlx, game->buf3d);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
