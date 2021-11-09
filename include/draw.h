/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:09:21 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 15:51:03 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "buffer.h"

void	draw_rect(t_buffer *buf, t_vec2 tl, t_vec2 br, uint32_t c);
void	draw_line(t_buffer *buf, t_vec2 p0, t_vec2 p1, uint32_t c);

#endif
