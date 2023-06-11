/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:24:51 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/10 15:53:32 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_mlx *vlx)
{
	if (vlx->map[(int)vlx->ray.pos_y]
		[(int)(vlx->ray.pos_x + vlx->ray.dir_x * MOVE_SPEED)] != '1')
		vlx->ray.pos_x += vlx->ray.dir_x * MOVE_SPEED;
	if (vlx->map[(int)(vlx->ray.pos_y + vlx->ray.dir_y * MOVE_SPEED)]
		[(int)vlx->ray.pos_x] != '1')
		vlx->ray.pos_y += vlx->ray.dir_y * MOVE_SPEED;
}

void	move_backwards(t_mlx *vlx)
{
	if (vlx->map[(int)vlx->ray.pos_y]
		[(int)(vlx->ray.pos_x - vlx->ray.dir_x * MOVE_SPEED)] != '1')
		vlx->ray.pos_x -= vlx->ray.dir_x * MOVE_SPEED;
	if (vlx->map[(int)(vlx->ray.pos_y - vlx->ray.dir_y * MOVE_SPEED)]
		[(int)vlx->ray.pos_x] != '1')
		vlx->ray.pos_y -= vlx->ray.dir_y * MOVE_SPEED;
}

void	move_left(t_mlx *vlx)
{
	if (vlx->map[(int)vlx->ray.pos_y]
		[(int)(vlx->ray.pos_x + vlx->ray.dir_y * MOVE_SPEED)] != '1')
		vlx->ray.pos_x += vlx->ray.dir_y * MOVE_SPEED;
	if (vlx->map[(int)(vlx->ray.pos_y - vlx->ray.dir_x * MOVE_SPEED)]
		[(int)vlx->ray.pos_x] != '1')
		vlx->ray.pos_y -= vlx->ray.dir_x * MOVE_SPEED;
}

void	move_right(t_mlx *vlx)
{
	if (vlx->map[(int)vlx->ray.pos_y]
		[(int)(vlx->ray.pos_x - vlx->ray.dir_y * MOVE_SPEED)] != '1')
		vlx->ray.pos_x -= vlx->ray.dir_y * MOVE_SPEED;
	if (vlx->map[(int)(vlx->ray.pos_y + vlx->ray.dir_x * MOVE_SPEED)]
		[(int)vlx->ray.pos_x] != '1')
		vlx->ray.pos_y += vlx->ray.dir_x * MOVE_SPEED;
}

void	rotate_right(t_mlx *vlx)
{
	double	old_direction_x;
	double	old_plane_x;

	old_direction_x = vlx->ray.dir_x;
	vlx->ray.dir_x = vlx->ray.dir_x * cos(ROTATE_SPEED)
		- vlx->ray.dir_y * sin(ROTATE_SPEED);
	vlx->ray.dir_y = old_direction_x * sin(ROTATE_SPEED)
		+ vlx->ray.dir_y * cos(ROTATE_SPEED);
	old_plane_x = vlx->ray.plane_x;
	vlx->ray.plane_x = vlx->ray.plane_x * cos(ROTATE_SPEED)
		- vlx->ray.plane_y * sin(ROTATE_SPEED);
	vlx->ray.plane_y = old_plane_x * sin(ROTATE_SPEED)
		+ vlx->ray.plane_y * cos(ROTATE_SPEED);
}
