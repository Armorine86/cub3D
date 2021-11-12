/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:51:19 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/12 15:14:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# define N_TEXTURES 4


typedef enum e_pos
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
}	t_pos;

typedef struct s_textures
{
	void	*img;
	char	*file;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		pitch;
	int		endian;
}	t_textures;


#endif
