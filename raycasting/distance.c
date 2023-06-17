/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:04:30 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/17 11:25:42 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_the_distance_to_the_next_x_or_y_side(t_mlx *vlx)
{
	if (vlx->ray.ray_dir_x == 0)
		vlx->ray.delta_dist_x = 1e30;
	else
		vlx->ray.delta_dist_x = fabs(1 / vlx->ray.ray_dir_x);
	if (vlx->ray.ray_dir_y == 0)
		vlx->ray.delta_dist_y = 1e30;
	else
		vlx->ray.delta_dist_y = fabs(1 / vlx->ray.ray_dir_y);
}

void	calculate_the_step_and_initial_side_distance_x(t_mlx *vlx)
{
	if (vlx->ray.ray_dir_x < 0)
	{
		vlx->ray.step_x = -1;
		vlx->ray.side_dist_x = (vlx->ray.pos_x - vlx->ray.map_x)
			* vlx->ray.delta_dist_x;
	}
	else
	{
		vlx->ray.step_x = 1;
		vlx->ray.side_dist_x = (vlx->ray.map_x + 1.0 - vlx->ray.pos_x)
			* vlx->ray.delta_dist_x;
	}
}

void	calculate_the_step_and_initial_side_distance_y(t_mlx *vlx)
{
	if (vlx->ray.ray_dir_y < 0)
	{
		vlx->ray.step_y = -1;
		vlx->ray.side_dist_y = (vlx->ray.pos_y - vlx->ray.map_y)
			* vlx->ray.delta_dist_y;
	}
	else
	{
		vlx->ray.step_y = 1;
		vlx->ray.side_dist_y = (vlx->ray.map_y + 1.0 - vlx->ray.pos_y)
			* vlx->ray.delta_dist_y;
	}
}

void	set_texture(t_mlx *vlx)
{
	if (vlx->ray.side == 0)
	{
		if (vlx->ray.map_x > vlx->ray.pos_x)
			vlx->ray.text_num = 1;
		else
			vlx->ray.text_num = 3;
	}
	else
	{
		if (vlx->ray.map_y > vlx->ray.pos_y)
			vlx->ray.text_num = 2;
		else
			vlx->ray.text_num = 0;
	}
}

void	perform_digital_differential_analysis(t_mlx *vlx)
{
	while (vlx->ray.hit == 0 && vlx->map[vlx->ray.map_y][vlx->ray.map_x])
	{
		if (vlx->ray.side_dist_x < vlx->ray.side_dist_y)
		{
			vlx->ray.side_dist_x += vlx->ray.delta_dist_x;
			vlx->ray.map_x += vlx->ray.step_x;
			vlx->ray.side = 0;
		}
		else
		{
			vlx->ray.side_dist_y += vlx->ray.delta_dist_y;
			vlx->ray.map_y += vlx->ray.step_y;
			vlx->ray.side = 1;
		}
		if (vlx->map[vlx->ray.map_y][vlx->ray.map_x] == '1')
		{
			vlx->ray.hit = 1;
			set_texture(vlx);
		}
	}
}
