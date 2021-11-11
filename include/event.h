/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:09:37 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/10 22:42:36 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "game.h"

int	keydown(int key, t_game *game);
int	keyup(int key, t_game *game);

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5
# define MOTION_NOTIFY 6
# define ENTER_NOTIFY 7
# define LEAVE_NOTIFY 8
# define FOCUS_IN 9
# define FOCUS_OUT 10
# define KEYMAP_NOTIFY 11
# define EXPOSE 12
# define GRAPHICS_EXPOSE 13
# define NO_EXPOSE 14
# define VISIBILITY_NOTIFY 15
# define CREATE_NOTIFY 16
# define DESTROY_NOTIFY 17
# define UNMAP_NOTIFY 18
# define MAP_NOTIFY 19
# define MAP_REQUEST 20
# define REPARENT_NOTIFY 21
# define CONFIGURE_NOTIFY 22
# define CONFIGURE_REQUEST 23
# define GRAVITY_NOTIFY 24
# define RESIZE_REQUEST 25
# define CIRCULATE_NOTIFY 26
# define CIRCULATE_REQUEST 27
# define PROPERTY_NOTIFY 28
# define SELECTION_CLEAR 29
# define SELECTION_REQUEST 30
# define SELECTION_NOTIFY 31
# define COLORMAP_NOTIFY 32
# define CLIENT_MESSAGE 33
# define MAPPING_NOTIFY 34
# define GENERIC_EVENT 35
# define LAST_EVENT 36

# define NO_EVENT_MASK 0x0L
# define KEY_PRESS_MASK 0x1L
# define KEY_RELEASE_MASK 0x2L
# define BUTTON_PRESS_MASK 0x4L
# define BUTTON_RELEASE_MASK 0x8L
# define ENTER_WINDOW_MASK 0x10L
# define LEAVE_WINDOW_MASK 0x20L
# define POINTER_MOTION_MASK 0x40L
# define POINTER_MOTION_HINT_MASK 0x80L
# define BUTTON1_MOTION_MASK 0x100L
# define BUTTON2_MOTIONMASK 0x200L
# define BUTTON3_MOTION_MASK 0x400L
# define BUTTON4_MOTION_MASK 0x800L
# define BUTTON5_MOTION_MASK 0x1000L
# define BUTTON_MOTION_MASK 0x2000L
# define KEYMAP_STATE_MASK 0x4000L
# define EXPOSURE_MASK 0x8000L
# define VISIBILITY_CHANGE_MASK 0x10000L
# define STRUCTURE_NOTIFY_MASK 0x20000L
# define RESIZE_REDIRECT_MASK 0x40000L
# define SUBSTRUCTURE_NOTIFY_MASK 0x80000L
# define SUBSTRUCTURE_REDIRECT_MASK 0x100000L
# define FOCUS_CHANGE_MASK 0x200000L
# define PROPERTY_CHANGE_MASK 0x400000L
# define COLORMAP_CHANGE_MASK 0x800000L
# define OWNER_GRAB_BUTTON_MASK 0x1000000L

#endif
