/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:52:26 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 23:57:10 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <libft/libft.h>
# include "keymap.h"
typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
}	t_player;

void	update_player(t_player *player, bool keystate[4], float speed)
{
	if (keystate[W])
	{
		player->pos.x += player->dir.x * speed;
		player->pos.y += player->dir.y * speed;
	}
	if (keystate[S])
	{
		player->pos.x -= player->dir.x * speed;
		player->pos.y -= player->dir.y * speed;
	}
}

#endif
