/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:11:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 00:34:34 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

typedef struct s_buffer
{
	void	*mlx;
	void	*img;
	char	*data;
	int		bpp;
	int		pitch;
	int		endian;
}	t_buffer;

t_buffer	*new_buffer(void *mlx_ptr, int width, int height);
void		destroy_buffer(t_buffer *buf);
void		put_pixel(t_buffer *buf, int x, int y, unsigned int rgb);

#endif
