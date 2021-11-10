/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:55:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 13:23:19 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <math.h>

static void	move_left(t_player *p, float speed)
{
	t_vec2	left;

	left.x = cosf(p->angle - PI_F / 2.0f);
	left.y = sinf(p->angle - PI_F / 2.0f);
	p->pos = vec2_add(p->pos, vec2_mul(left, speed));
}

static void	move_right(t_player *p, float speed)
{
	t_vec2	right;

	right.x = cosf(p->angle + PI_F / 2.0f);
	right.y = sinf(p->angle + PI_F / 2.0f);
	p->pos = vec2_add(p->pos, vec2_mul(right, speed));
}

void	update_player(t_player *p, bool keystate[N_KEYS], float speed)
{
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
	if (keystate[W])
		p->pos = vec2_add(p->pos, vec2_mul(p->dir, speed));
	if (keystate[S])
		p->pos = vec2_sub(p->pos, vec2_mul(p->dir, speed));
	if (keystate[A])
		move_left(p, speed);
	if (keystate[D])
		move_right(p, speed);
}
