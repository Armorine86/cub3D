/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:55:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 14:46:54 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <math.h>

static t_vec2	move_left(t_player *p)
{
	t_vec2	left;

	left.x = cosf(p->angle - PI_F / 2.0f);
	left.y = sinf(p->angle - PI_F / 2.0f);
	return (left);
}

static t_vec2	move_right(t_player *p)
{
	t_vec2	right;

	right.x = cosf(p->angle + PI_F / 2.0f);
	right.y = sinf(p->angle + PI_F / 2.0f);
	return (right);
}

void	update_player(t_player *p, bool keystate[N_KEYS], float speed)
{
	t_vec2	move_dir;

	if (keystate[LEFT])
	{
		p->angle = wrap_angle(p->angle - 0.1f);
		p->dir = vec2_rotate(p->dir, p->angle);
	}
	if (keystate[RIGHT])
	{
		p->angle = wrap_angle(p->angle + 0.1f);
		p->dir = vec2_rotate(p->dir, p->angle);
	}
	move_dir = (t_vec2){0, 0};
	if (keystate[W])
		move_dir = vec2_add(move_dir, p->dir);
	if (keystate[S])
		move_dir = vec2_sub(move_dir, p->dir);
	if (keystate[A])
		move_dir = vec2_add(move_dir, move_left(p));
	if (keystate[D])
		move_dir = vec2_add(move_dir, move_right(p));
	move_dir = vec2_normalize(move_dir);
	p->pos = vec2_add(p->pos, vec2_mul(move_dir, speed));
}
