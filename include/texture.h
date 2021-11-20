/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:51:19 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/19 08:43:01 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# define N_TEXTURES 4

# include "side.h"
# include <stdint.h>

typedef struct s_texture
{
	void	*img;
	char	*data;
	int		w;
	int		h;
	int		width;
	int		height;
	int		bpp;
	int		pitch;
	int		endian;
}	t_texture;

t_texture	*new_texture(void *mlx, const char *file);
uint32_t	get_tex_pixel(t_texture *t, int32_t x, int32_t y);
void		free_texture(void *mlx, t_texture *t);
char		**extract_tex_data(int fd);


#endif
