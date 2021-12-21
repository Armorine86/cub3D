/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:55:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/21 18:26:32 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "config.h"
#include <math.h>

static void	rotate(t_player *p, double angle)
{
	p->angle = ft_wrap_angle(angle);
	p->dir = ft_vec2_unit(p->angle);
	p->c_plane = ft_vec2_unit(p->angle + ft_deg_to_rad(90.0));
	p->c_plane = ft_vec2_mul(p->c_plane, p->fov_ratio);
}

static t_vec2	collide_walls(t_vec2 pos, t_vec2 dir, double speed, t_world *w)
{
	int32_t	x;
	int32_t	y;
	t_vec2	move;

	x = ft_clamp((int64_t)(pos.x + dir.x * 0.2), 0, w->width - 1);
	y = ft_clamp((int64_t)(pos.y + dir.y * 0.2), 0, w->height - 1);
	move = ft_vec2_mul(dir, speed);
	if (w->map[(int32_t)pos.y][x] == MAP_EMPTY)
		pos.x += move.x;
	if (w->map[y][(int32_t)pos.x] == MAP_EMPTY)
		pos.y += move.y;
	return (pos);
}

static void	mouse_movement(t_player *p, double dt, t_mouse *m)
{
	int32_t	dx;
	double	speed;

	if (m->new_event)
	{
		speed = 1.0 / PI;
		dx = m->pos.x - m->old_pos.x;
		m->new_event = false;
		rotate(p, p->angle + ((double)dx * speed * dt));
	}
}

void	update_player(t_player *p, bool keys[N_KEYS], double dt, t_game *g)
{
	t_vec2	move_dir;
	t_vec2	d;

	if (keys[ARROW_LEFT])
		rotate(p, p->angle - A_SPEED * dt);
	if (keys[ARROW_RIGHT])
		rotate(p, p->angle + A_SPEED * dt);
	mouse_movement(p, dt, &g->mouse);
	move_dir = (t_vec2){0, 0};
	if (keys[W])
		move_dir = ft_vec2_add(move_dir, p->dir);
	if (keys[S])
		move_dir = ft_vec2_sub(move_dir, p->dir);
	if (keys[A] && !keys[D])
	{
		d = ft_vec2_unit(p->angle - ft_deg_to_rad(90.0));
		move_dir = ft_vec2_add(move_dir, d);
	}
	if (keys[D] && !keys[A])
	{
		d = ft_vec2_unit(p->angle + ft_deg_to_rad(90.0));
		move_dir = ft_vec2_add(move_dir, d);
	}
	move_dir = ft_vec2_normalize(move_dir);
	p->pos = collide_walls(p->pos, move_dir, SPEED * dt, g->world);
}
