/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 15:05:40 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <libft/libft.h>
#include "buffer.h"
#include "draw.h"
#include "utils.h"

#define WIDTH 800
#define HEIGHT 600

int	mouse_fn(int x, int y, void *data)
{
	t_buffer	*buf;

	buf = data;
	clear(buf, 0x777777);
	draw_line(buf, (t_vec2){400.0f, 300.0f},
		(t_vec2){(float)x, (float)y}, 0x00FFFF00);
	mlx_put_image_to_window(buf->mlx, buf->win, buf->img, 0, 0);
	return (0);
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_buffer	*buf;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "cub3D");
	buf = new_buffer(mlx, win, WIDTH, HEIGHT);
	draw_rect(buf, (t_vec2i){0, 0}, (t_vec2i){800, 600}, 0x777777);
	mlx_hook(win, 6, 1 << 6, &mouse_fn, buf);
	mlx_loop(mlx);
}
