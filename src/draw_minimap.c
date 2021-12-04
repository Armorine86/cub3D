/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:49:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/03 20:02:56 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_minimap(t_buffer *buf, t_world *world)
{
	t_vec2	tl;
	t_vec2	br;

	tl = (t_vec2){5.0, 5.0};
	br = (t_vec2){125.0, 80.0};
	(void)world;
	draw_rect(buf, tl, br, 0xCCCCCC);
}
