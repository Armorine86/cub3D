/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:52:26 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/01 15:15:47 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <libft/libft.h>
# include "keymap.h"
# include "world.h"

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	double	angle;
	t_vec2	c_plane;
	double	fov_ratio;
}	t_player;

void	update_player(t_player *p, bool keys[N_KEYS], double dt, t_world *w);

#endif
