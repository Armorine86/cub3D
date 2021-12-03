/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:14:21 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/03 05:00:26 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static double	get_angle(char side)
{
	if (side == UP)
		return (ft_deg_to_rad(270));
	if (side == DOWN)
		return (ft_deg_to_rad(90));
	if (side == LEFT)
		return (ft_deg_to_rad(180));
	return (ft_deg_to_rad(0));
}

void	get_spawn_location(char **map, t_vec2 *spawn, double *angle)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr(SPAWN, map[y][x]))
			{
				*angle = get_angle(map[y][x]);
				map[y][x] = MAP_EMPTY;
				*spawn = (t_vec2){(double)x + 0.5, (double)y + 0.5};
				return ;
			}
			x++;
		}
		y++;
	}
}
