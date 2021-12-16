/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:17:39 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/16 13:32:59 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "config.h"

int	update(t_game *g)
{
	int32_t	w;
	int32_t	h;

	g->dt = 0.01;
	update_player(&g->player, g->keystate, g->dt, g);
	w = g->buf3d->w;
	h = g->buf3d->h;
	draw_rect(g->buf3d, (t_vec2){0, 0}, (t_vec2){w, h / 2}, g->world->ceiling);
	draw_rect(g->buf3d, (t_vec2){0, h / 2}, (t_vec2){w, h}, g->world->floor);
	draw_view(g->buf3d, &g->player, g->world->tex, g->world->map);
	draw_minimap(g->minimap, g->world, &g->player);
	draw_crosshair(g->buf3d, CROSSHAIR_COLOR);
	update_screen(g);
	return (0);
}
