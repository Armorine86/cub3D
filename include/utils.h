/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:47:28 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/19 19:58:33 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <libft/libft.h>
# include "side.h"

uint32_t	make_argb(uint8_t t, uint8_t r, uint8_t g, uint8_t b);
uint32_t	argb_mul(uint32_t c, double factor);
void		vec2_swap(t_vec2 *a, t_vec2 *b);
bool		is_vertical(t_side side);
bool		is_horizontal(t_side side);

#endif
