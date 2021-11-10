/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/09 22:23:50 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <libft/libft.h>
#include <stdint.h>
#include "draw.h"
#include "utils.h"

#define WIDTH 800
#define HEIGHT 600
#define SQUARE_SIZE 100
#define PAD_SIZE 3

static const int	g_map[6][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

void	draw_grid(t_buffer *buf)
{
	int32_t	x;
	int32_t	y;
	float	py;
	float	px;
	t_vec2	p;

	y = 0;
	while (y < HEIGHT / SQUARE_SIZE)
	{
		x = 0;
		py = (float)(y * SQUARE_SIZE);
		while (x < WIDTH / SQUARE_SIZE)
		{
			px = (float)(x * SQUARE_SIZE);
			p.x = px + SQUARE_SIZE - PAD_SIZE;
			p.y = py + SQUARE_SIZE - PAD_SIZE;
			if (g_map[y][x] == 1)
				draw_rect(buf, (t_vec2){px, py}, p, 0xFFFFFF);
			else
				draw_rect(buf, (t_vec2){px, py}, p, 0x0);
			x++;
		}
		y++;
	}
}

int	update(void *data)
{
	t_buffer	*buf;

	buf = data;
	clear_buffer(buf, 0);
	draw_grid(buf);
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
	mlx_loop_hook(mlx, &update, buf);
	mlx_loop(mlx);
}
