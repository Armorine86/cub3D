/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:55:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/18 08:12:04 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "fixed_map.h"
#include <math.h>

static void	rotate_left(t_player *p, double dt)
{
	p->angle = wrap_angle(p->angle - A_SPEED * dt);
	p->dir = vec2_unit(p->angle);
	p->c_plane = vec2_unit(p->angle + deg_to_rad(90.0));
	p->c_plane = vec2_mul(p->c_plane, p->fov_ratio);
}

static void	rotate_right(t_player *p, double dt)
{
	p->angle = wrap_angle(p->angle + A_SPEED * dt);
	p->dir = vec2_unit(p->angle);
	p->c_plane = vec2_unit(p->angle + deg_to_rad(90.0));
	p->c_plane = vec2_mul(p->c_plane, p->fov_ratio);
}

static t_vec2	collide_walls(t_vec2 pos, t_vec2 move)
{
	if (!g_map[(int32_t)pos.y][(int32_t)(pos.x + move.x)])
		pos.x += move.x;
	if (!g_map[(int32_t)(pos.y + move.y)][(int32_t)pos.x])
		pos.y += move.y;
	return (pos);
}

void	update_player(t_player *p, bool keystate[N_KEYS], double dt)
{
	t_vec2	move_dir;

	if (keystate[LEFT])
		rotate_left(p, dt);
	if (keystate[RIGHT])
		rotate_right(p, dt);
	move_dir = (t_vec2){0, 0};
	if (keystate[W])
		move_dir = vec2_add(move_dir, p->dir);
	if (keystate[S])
		move_dir = vec2_sub(move_dir, p->dir);
	if (keystate[A] && !keystate[D])
		move_dir = vec2_add(move_dir, vec2_unit(p->angle - deg_to_rad(90.0)));
	if (keystate[D] && !keystate[A])
		move_dir = vec2_add(move_dir, vec2_unit(p->angle + deg_to_rad(90.0)));
	move_dir = vec2_normalize(move_dir);
	p->pos = collide_walls(p->pos, vec2_mul(move_dir, SPEED * dt));
}
