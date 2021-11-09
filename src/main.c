/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 00:59:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <libft/libft.h>
#include "buffer.h"
#include "utils.h"

#define WIDTH 800
#define HEIGHT 600

int	main(void)
{
	void		*mlx;
	void		*win;
	t_buffer	*buf;
	int32_t		i;
	int32_t		j;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "cub3D");
	buf = new_buffer(mlx, WIDTH, HEIGHT);
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			put_pixel(buf, i, j, make_trgb(0xFF, 0x88, 0x88, 0x88));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx, win, buf->img, 0, 0);
	mlx_loop(mlx);
}
