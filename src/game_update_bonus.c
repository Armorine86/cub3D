/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:17:39 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/15 12:52:12 by mmondell         ###   ########.fr       */
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
	update_player(&g->player, g->keystate, g->dt, g);
	w = g->buf3d->w;
	h = g->buf3d->h;
	draw_fc(g->buf3d, &g->player, g->world->tex[FLOOR],
		g->world->tex[CEILING]);
	draw_view(g->buf3d, &g->player, g->world->tex, g->world->map);
	draw_minimap(g->minimap, g->world, &g->player);
	update_screen(g);
	return (0);
}
