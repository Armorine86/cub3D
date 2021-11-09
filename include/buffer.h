/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:11:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 12:37:38 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include <libft/libft.h>
# include <stdint.h>

typedef struct s_buffer
{
	void	*mlx;
	void	*img;
	char	*data;
	int32_t	bpp;
	int32_t	pitch;
	int32_t	endian;
}	t_buffer;

t_buffer	*new_buffer(void *mlx_ptr, int32_t width, int32_t height);
void		destroy_buffer(t_buffer *buf);
void		put_pixel(t_buffer *buf, int32_t x, int32_t y, uint32_t trgb);
void		draw_rect(t_buffer *buf, t_vec2i tl, t_vec2i br, uint32_t c);
void		draw_line(t_buffer *buf, t_vec2i p0, t_vec2i p1, uint32_t c);

#endif
