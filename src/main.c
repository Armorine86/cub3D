/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 12:37:58 by mmondell         ###   ########.fr       */
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

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "cub3D");
	buf = new_buffer(mlx, WIDTH, HEIGHT);
	draw_rect(buf, (t_vec2i){0, 0}, (t_vec2i){800, 600}, 0x424242);
	draw_line(buf, (t_vec2i){250, 250}, (t_vec2i){75, 50}, 0xFFFF00);
	mlx_put_image_to_window(mlx, win, buf->img, 0, 0);
	mlx_loop(mlx);
}
