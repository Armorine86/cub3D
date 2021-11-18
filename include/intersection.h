/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:31:31 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/17 01:56:06 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <libft/libft.h>

typedef enum e_side
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}	t_side;

typedef struct s_hit
{
	t_vec2	pos;
	double	dist;
	t_side	side;
}	t_hit;

bool	intersect(t_vec2 pos, t_vec2 dir, t_hit *hit);

#endif
