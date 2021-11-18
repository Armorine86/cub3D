/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:11:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/18 13:40:37 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include <libft/libft.h>
# include <stdint.h>

typedef struct s_buffer
{
	void	*img;
	char	*data;
	int32_t	bpp;
	int32_t	pitch;
	int32_t	endian;
	int32_t	w;
	int32_t	h;
}	t_buffer;

t_buffer	*new_buffer(void *mlx, int32_t w, int32_t h);
void		destroy_buffer(void *mlx, t_buffer *buf);
void		put_pixel(t_buffer *buf, int32_t x, int32_t y, uint32_t c);
void		clear_buffer(t_buffer *buf, uint32_t c);

#endif
