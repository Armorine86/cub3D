/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:38:48 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 13:26:46 by mleblanc         ###   ########.fr       */
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
#  define KEY_LEFT 0x7B
#  define KEY_RIGHT 0x7C

# elif __APPLE__

#  define KEY_W 0x0D
#  define KEY_A 0x00
#  define KEY_S 0x01
#  define KEY_D 0x02
#  define KEY_ESC 0x35
#  define KEY_LEFT 0x7B
#  define KEY_RIGHT 0x7C

# endif

# define N_KEYS 6

typedef enum s_key
{
	W,
	A,
	S,
	D,
	LEFT,
	RIGHT
}	t_key;

#endif
