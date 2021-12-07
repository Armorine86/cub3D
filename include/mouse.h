/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:34:14 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/07 14:35:43 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include <libft/libft.h>

typedef struct s_mouse
{
	t_vec2i	pos;
	t_vec2i	old_pos;
}	t_mouse;

#endif
