/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:31:31 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/20 20:30:36 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <libft/libft.h>
# include "side.h"

typedef struct s_hit
{
	t_vec2	pos;
	double	dist;
	t_side	side;
	t_vec2i	map_pos;
}	t_hit;

void	intersect(t_vec2 pos, t_vec2 dir, t_hit *hit);

#endif
