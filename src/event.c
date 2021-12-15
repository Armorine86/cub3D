/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:10:56 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/13 22:54:04 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	keydown(int key, t_game *game)
{
	if (key == KEY_W)
		game->keystate[W] = true;
	else if (key == KEY_A)
		game->keystate[A] = true;
	else if (key == KEY_S)
		game->keystate[S] = true;
	else if (key == KEY_D)
		game->keystate[D] = true;
	else if (key == KEY_LEFT)
		game->keystate[ARROW_LEFT] = true;
	else if (key == KEY_RIGHT)
		game->keystate[ARROW_RIGHT] = true;
	else if (key == KEY_M)
	{
		game->mouse_enabled = !game->mouse_enabled;
		game->mouse.old_pos = (t_vec2i){0, 0};
		game->mouse.pos = (t_vec2i){0, 0};
	}
	else if (key == KEY_ESC)
		quit_game(game);
	return (0);
}

int	keyup(int key, t_game *game)
{
	if (key == KEY_W)
		game->keystate[W] = false;
	else if (key == KEY_A)
		game->keystate[A] = false;
	else if (key == KEY_S)
		game->keystate[S] = false;
	else if (key == KEY_D)
		game->keystate[D] = false;
	else if (key == KEY_LEFT)
		game->keystate[ARROW_LEFT] = false;
	else if (key == KEY_RIGHT)
		game->keystate[ARROW_RIGHT] = false;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	if (game->mouse_enabled)
	{
		game->mouse.old_pos = game->mouse.pos;
		game->mouse.pos.x = x;
		game->mouse.pos.y = y;
	}
	return (0);
}
