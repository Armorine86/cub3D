/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:09:21 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/16 13:32:00 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "buffer.h"
# include "player.h"
# include "texture.h"
# include "intersection.h"
# include "world.h"

typedef struct s_fc
{
	t_vec2i		iter;
	t_vec2		step;
	t_vec2		pos;
	double		row_dist;
}	t_fc;

typedef struct s_lineinfo
{
	int32_t	start;
	int32_t	end;
	int32_t	h;
	double	wall_x;
	t_hit	hit;
	t_vec2	ray_dir;
}	t_lineinfo;

void	draw_rect(t_buffer *buf, t_vec2 tl, t_vec2 br, uint32_t c);
void	draw_rect_center(t_buffer *buf, t_vec2 center, t_vec2 wh, uint32_t c);
void	draw_line(t_buffer *buf, t_vec2 p0, t_vec2 p1, uint32_t c);
void	draw_circle(t_buffer *buf, t_vec2 center, double r, uint32_t c);
void	draw_grid(t_buffer *buf);
void	draw_player(t_buffer *buf, t_player *player);
void	draw_fc(t_buffer *buf, t_player *p, t_texture *fl, t_texture *c);
void	draw_view(t_buffer *buf, t_player *p, t_texture *t[N_TEX], char **map);
void	draw_line_tex(t_buffer *buf, t_texture *t, t_lineinfo info, int32_t x);
void	draw_minimap(t_buffer *buf, t_world *world, t_player *p);
void	draw_crosshair(t_buffer *buf, uint32_t color);

#endif
