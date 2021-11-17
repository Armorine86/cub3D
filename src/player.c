/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:55:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/17 02:39:50 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "config.h"
#include <math.h>

static void	rotate_left(t_player *p, double dt)
{
	p->angle = wrap_angle(p->angle - A_SPEED * dt);
	p->dir = vec2_unit(p->angle);
	p->c_plane = vec2_unit(p->angle + deg_to_rad(90.0));
	p->c_plane = vec2_mul(p->c_plane, 0.66);
}

static void	rotate_right(t_player *p, double dt)
{
	p->angle = wrap_angle(p->angle + A_SPEED * dt);
	p->dir = vec2_unit(p->angle);
	p->c_plane = vec2_unit(p->angle + deg_to_rad(90.0));
	p->c_plane = vec2_mul(p->c_plane, 0.66);
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
	p->pos = vec2_add(p->pos, vec2_mul(move_dir, SPEED * dt));
}
