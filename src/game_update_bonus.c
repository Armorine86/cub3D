/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:17:39 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/16 19:54:07 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "config.h"

int	update(t_game *g)
{
	t_time	t;

	ft_gettime(&t);
	g->dt = (float)ft_timediff(g->last_frame, t);
	g->last_frame = t;
	update_player(&g->player, g->keystate, g->dt, g);
	draw_fc(g->buf3d, &g->player, g->world->tex[FLOOR],
		g->world->tex[CEILING]);
	draw_view(g->buf3d, &g->player, g->world->tex, g->world->map);
	draw_minimap(g->minimap, g->world, &g->player);
	draw_crosshair(g->buf3d, CROSSHAIR_COLOR);
	update_screen(g);
	return (0);
}
