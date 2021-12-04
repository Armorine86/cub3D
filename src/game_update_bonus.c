/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:17:39 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/03 19:53:59 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"

int	update(t_game *g)
{
	t_time	t;
	int32_t	w;
	int32_t	h;

	ft_gettime(&t);
	g->dt = (float)ft_timediff(g->last_frame, t);
	g->last_frame = t;
	update_player(&g->player, g->keystate, g->dt, g->world);
	w = g->buf3d->w;
	h = g->buf3d->h;
	draw_rect(g->buf3d, (t_vec2){0, 0}, (t_vec2){w, h / 2}, g->world->ceiling);
	draw_rect(g->buf3d, (t_vec2){0, h / 2}, (t_vec2){w, h}, g->world->floor);
	draw_view(g->buf3d, &g->player, g->world->tex, g->world->map);
	draw_minimap(g->buf3d, g->world);
	update_screen(g);
	return (0);
}
