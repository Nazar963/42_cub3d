/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:24:51 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/23 16:41:21 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move_forward(t_mlx *vlx)
{
	if (vlx->map[(int)vlx->ray.pos_y]
		[(int)(vlx->ray.pos_x + vlx->ray.dir_x * vlx->ray.move_speed)] != '1')
		vlx->ray.pos_x += vlx->ray.dir_x * vlx->ray.move_speed;
	if (vlx->map[(int)(vlx->ray.pos_y + vlx->ray.dir_y * vlx->ray.move_speed)]
		[(int)vlx->ray.pos_x] != '1')
		vlx->ray.pos_y += vlx->ray.dir_y * vlx->ray.move_speed;
}

void	player_move_backwards(t_mlx *vlx)
{
	if (vlx->map[(int)vlx->ray.pos_y]
		[(int)(vlx->ray.pos_x - vlx->ray.dir_x * vlx->ray.move_speed)] != '1')
		vlx->ray.pos_x -= vlx->ray.dir_x * vlx->ray.move_speed;
	if (vlx->map[(int)(vlx->ray.pos_y - vlx->ray.dir_y * vlx->ray.move_speed)]
		[(int)vlx->ray.pos_x] != '1')
		vlx->ray.pos_y -= vlx->ray.dir_y * vlx->ray.move_speed;
}

void	player_move_left(t_mlx *vlx)
{
	if (vlx->map[(int)vlx->ray.pos_y]
		[(int)(vlx->ray.pos_x + vlx->ray.dir_y * vlx->ray.move_speed)] != '1')
		vlx->ray.pos_x += vlx->ray.dir_y * vlx->ray.move_speed;
	if (vlx->map[(int)(vlx->ray.pos_y - vlx->ray.dir_x * vlx->ray.move_speed)]
		[(int)vlx->ray.pos_x] != '1')
		vlx->ray.pos_y -= vlx->ray.dir_x * vlx->ray.move_speed;
}

void	player_move_right(t_mlx *vlx)
{
	if (vlx->map[(int)vlx->ray.pos_y]
		[(int)(vlx->ray.pos_x - vlx->ray.dir_y * vlx->ray.move_speed)] != '1')
		vlx->ray.pos_x -= vlx->ray.dir_y * vlx->ray.move_speed;
	if (vlx->map[(int)(vlx->ray.pos_y + vlx->ray.dir_x * vlx->ray.move_speed)]
		[(int)vlx->ray.pos_x] != '1')
		vlx->ray.pos_y += vlx->ray.dir_x * vlx->ray.move_speed;
}

void	player_rotate_right(t_mlx *vlx)
{
	double	old_direction_x;
	double	old_plane_x;

	old_direction_x = vlx->ray.dir_x;
	vlx->ray.dir_x = vlx->ray.dir_x * cos(vlx->ray.rotate_speed)
		- vlx->ray.dir_y * sin(vlx->ray.rotate_speed);
	vlx->ray.dir_y = old_direction_x * sin(vlx->ray.rotate_speed)
		+ vlx->ray.dir_y * cos(vlx->ray.rotate_speed);
	old_plane_x = vlx->ray.plane_x;
	vlx->ray.plane_x = vlx->ray.plane_x * cos(vlx->ray.rotate_speed)
		- vlx->ray.plane_y * sin(vlx->ray.rotate_speed);
	vlx->ray.plane_y = old_plane_x * sin(vlx->ray.rotate_speed)
		+ vlx->ray.plane_y * cos(vlx->ray.rotate_speed);
}
