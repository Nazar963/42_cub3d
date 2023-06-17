/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:12:33 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/17 21:16:41 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_distance_projected_on_camera_direction(t_mlx *vlx)
{
	if (vlx->ray.side == 0)
		vlx->ray.perp_wall_dist = vlx->ray.side_dist_x - vlx->ray.delta_dist_x;
	else
		vlx->ray.perp_wall_dist = vlx->ray.side_dist_y - vlx->ray.delta_dist_y;
}

void	calculate_draw_start_and_draw_end(t_mlx *vlx)
{
	vlx->ray.draw_start = (-1) * vlx->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (vlx->ray.draw_start < 0)
		vlx->ray.draw_start = 0;
	vlx->ray.draw_end = vlx->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (vlx->ray.draw_end >= SCREEN_HEIGHT)
		vlx->ray.draw_end = SCREEN_HEIGHT - 1;
}

void	calculate_texture_x(t_mlx *vlx)
{
	if (vlx->ray.side == 0)
		vlx->ray.wall_x = vlx->ray.pos_y + vlx->ray.perp_wall_dist
			* vlx->ray.ray_dir_y;
	else
		vlx->ray.wall_x = vlx->ray.pos_x + vlx->ray.perp_wall_dist
			* vlx->ray.ray_dir_x;
	vlx->ray.wall_x -= floor(vlx->ray.wall_x);
	vlx->ray.text_x = (int)(vlx->ray.wall_x * (double)WALL_WIDTH);
	if ((vlx->ray.side == 0 && vlx->ray.ray_dir_x > 0)
	|| (vlx->ray.side == 1 && vlx->ray.dir_y < 0))
		vlx->ray.text_x = WALL_WIDTH - vlx->ray.text_x - 1;
}

void	draw_stripe_color_pixel(int i, t_mlx *vlx)
{
	double	step;
	double	wall_pos;
	int		y;

	step = 1.0 * WALL_HEIGHT / vlx->ray.line_height;
	wall_pos = (vlx->ray.draw_start - SCREEN_HEIGHT / 2
			+ vlx->ray.line_height / 2) * step;
	y = vlx->ray.draw_start;
	while (y < vlx->ray.draw_end)
	{
		vlx->ray.text_y = (int)wall_pos & (WALL_HEIGHT - 1);
		wall_pos += step;
		vlx->ray.color = vlx->wall[vlx->ray.text_num].add
		[WALL_HEIGHT * vlx->ray.text_y + vlx->ray.text_x];
		my_pixel_put(i, y, vlx->ray.color, vlx);
		y++;
	}
}
