/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:49:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/15 18:51:29 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "config.h"
#include <math.h>

uint32_t	get_color_fog(uint32_t c, double dist)
{
	double	visibility;

	if (!isnormal(dist))
		dist = 0;
	visibility = exp(-pow(dist * FOG_DENSITY, FOG_GRADIENT));
	visibility = ft_clampd(visibility, 0.0, 1.0);
	return (argb_mul(c, visibility));
}
