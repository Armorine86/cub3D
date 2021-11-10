/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:38:48 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 00:22:52 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

# ifdef __linux__

#  define KEY_W 0x77
#  define KEY_A 0x61
#  define KEY_S 0x73
#  define KEY_D 0x64
#  define KEY_ESC 0xFF1B

# elif __APPLE__

#  define KEY_W 0x0D
#  define KEY_A 0x00
#  define KEY_S 0x01
#  define KEY_D 0x02
#  define KEY_ESC 0x35

# endif

typedef enum s_key
{
	W,
	A,
	S,
	D
}	t_key;

#endif
