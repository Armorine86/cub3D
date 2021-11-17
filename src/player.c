/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:55:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/16 23:42:34 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "config.h"
#include <math.h>

static t_vec2	move_left(t_player *p)
{
	t_vec2	left;

	left.x = cos(p->angle - deg_to_rad(90.0));
	left.y = sin(p->angle - deg_to_rad(90.0));
	return (left);
}

static t_vec2	move_right(t_player *p)
{
	t_vec2	right;

	right.x = cos(p->angle + deg_to_rad(90.0));
	right.y = sin(p->angle + deg_to_rad(90.0));
	return (right);
}

void	update_player(t_player *p, bool keystate[N_KEYS], double dt)
{
	t_vec2	move_dir;

	if (keystate[LEFT])
	{
		p->angle = wrap_angle(p->angle - A_SPEED * dt);
		p->dir = vec2_rotate(p->dir, p->angle);
	}
	if (keystate[RIGHT])
	{
		p->angle = wrap_angle(p->angle + A_SPEED * dt);
		p->dir = vec2_rotate(p->dir, p->angle);
	}
	move_dir = (t_vec2){0, 0};
	if (keystate[W])
		move_dir = vec2_add(move_dir, p->dir);
	if (keystate[S])
		move_dir = vec2_sub(move_dir, p->dir);
	if (keystate[A] && !keystate[D])
		move_dir = vec2_add(move_dir, move_left(p));
	if (keystate[D] && !keystate[A])
		move_dir = vec2_add(move_dir, move_right(p));
	move_dir = vec2_normalize(move_dir);
	p->pos = vec2_add(p->pos, vec2_mul(move_dir, SPEED * dt));
}
