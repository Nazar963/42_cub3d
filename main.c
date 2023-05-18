/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:32:08 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/18 22:38:37 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(int x, int y, int color, t_mlx *vlx)
{
	char	*dst;

	dst = vlx->address + (y * vlx->line_length + x * (vlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//* ---------------------------------------------------------------------------------------------- */
//*                                           raycasting                                           */
//* ---------------------------------------------------------------------------------------------- */

void	get_ray_pos_dir(int i, t_mlx *vlx)
{
	vlx->ray.camera_x = 2 * i / (double)SCREEN_WIDTH - 1;
	vlx->ray.ray_dir_x = vlx->ray.dir_x + vlx->ray.plane_x * vlx->ray.camera_x;
	vlx->ray.ray_dir_y = vlx->ray.dir_y + vlx->ray.plane_y * vlx->ray.camera_x;
}

void	box_pos(t_mlx *vlx)
{
	vlx->ray.map_x = (int)vlx->ray.pos_x;
	vlx->ray.map_y = (int)vlx->ray.pos_y;
	vlx->ray.hit = 0;
}

void	delta_distance(t_mlx *vlx)
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

void	step_side_dist_x(t_mlx *vlx)
{
	if (vlx->ray.ray_dir_x < 0)
	{
		vlx->ray.step_x = -1;
		vlx->ray.side_dist_x = (vlx->ray.pos_x - vlx->ray.map_x) * vlx->ray.delta_dist_x;
	}
	else
	{
		vlx->ray.step_x = 1;
		vlx->ray.side_dist_x = (vlx->ray.map_x + 1.0 - vlx->ray.pos_x) * vlx->ray.delta_dist_x;
	}
}

void	step_side_dist_y(t_mlx *vlx)
{
	if (vlx->ray.ray_dir_y < 0)
	{
		vlx->ray.step_y = -1;
		vlx->ray.side_dist_y = (vlx->ray.pos_y - vlx->ray.map_y) * vlx->ray.delta_dist_y;
	}
	else
	{
		vlx->ray.step_y = 1;
		vlx->ray.side_dist_y = (vlx->ray.map_y + 1.0 - vlx->ray.pos_y) * vlx->ray.delta_dist_y;
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

void	algorithm_DDA(t_mlx *vlx)
{
	while (vlx->ray.hit == 0)
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

void	calculate_distance_perspective(t_mlx *vlx)
{
	if (vlx->ray.side == 0)
		vlx->ray.perp_wall_dist = vlx->ray.side_dist_x - vlx->ray.delta_dist_x;
	else
		vlx->ray.perp_wall_dist = vlx->ray.side_dist_y - vlx->ray.delta_dist_y;
}

void	calculate_vertical_line_height(t_mlx *vlx)
{
	vlx->ray.line_height = (int)(SCREEN_HEIGHT / vlx->ray.perp_wall_dist);
}

void	calculate_draw_start_and_draw_end(t_mlx *vlx)
{
	int	draw_start;

	draw_start = (-1) * vlx->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	vlx->ray.draw_start = draw_start;
	if (vlx->ray.draw_start < 0 )
		vlx->ray.draw_start = 0;
	vlx->ray.draw_end = vlx->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (vlx->ray.draw_end >= SCREEN_HEIGHT)
		vlx->ray.draw_end = SCREEN_HEIGHT - 1;
}

void	calculate_texture_x(t_mlx *vlx)
{
	if (vlx->ray.side == 0)
		vlx->ray.wall_x = vlx->ray.pos_y + vlx->ray.perp_wall_dist * vlx->ray.ray_dir_y;
	else
		vlx->ray.wall_x = vlx->ray.pos_x + vlx->ray.perp_wall_dist * vlx->ray.ray_dir_x;
	vlx->ray.wall_x -= floor(vlx->ray.wall_x);
	vlx->ray.text_x = (int)(vlx->ray.wall_x * (double)WALL_WIDTH);
	if (vlx->ray.side == 0 && vlx->ray.ray_dir_x > 0)
		vlx->ray.text_x = WALL_WIDTH - vlx->ray.text_x - 1;
	if (vlx->ray.side == 1 && vlx->ray.dir_y < 0)
		vlx->ray.text_x = WALL_WIDTH - vlx->ray.text_x - 1;
}

void	draw_vertical_texture_stripe(int i, t_mlx *vlx)
{
	double	step;
	double	wall_pos;
	int		y;

	step = 1.0 * WALL_HEIGHT / vlx->ray.line_height;
	wall_pos = (vlx->ray.draw_start - SCREEN_HEIGHT / 2 + vlx->ray.line_height / 2) * step;
	y = vlx->ray.draw_start;
	while (y < vlx->ray.draw_end)
	{
		vlx->ray.text_y = (int)wall_pos & (WALL_HEIGHT - 1);
		wall_pos += step;
		vlx->ray.color = vlx->wall_dim[vlx->ray.text_num][WALL_HEIGHT * vlx->ray.text_y + vlx->ray.text_x];
		if (vlx->ray.side == 1)
			vlx->ray.color = (vlx->ray.color >> 1) & 8355711;
		my_pixel_put(i, y, vlx->ray.color, vlx);
		y++;
	}
}

void	raycasting(t_mlx *vlx)
{
	int	i;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		get_ray_pos_dir(i, vlx);
		box_pos(vlx);
		delta_distance(vlx);
		step_side_dist_x(vlx);
		step_side_dist_y(vlx);
		algorithm_DDA(vlx);
		calculate_distance_perspective(vlx);
		calculate_vertical_line_height(vlx);
		calculate_draw_start_and_draw_end(vlx);
		calculate_texture_x(vlx);
		draw_vertical_texture_stripe(i, vlx);
		i++;
	}
}

//* ---------------------------------------------------------------------------------------------- */
//*                                            mlx_utils                                           */
//* ---------------------------------------------------------------------------------------------- */



//* ---------------------------------------------------------------------------------------------- */
//*                                          parse_colors                                          */
//* ---------------------------------------------------------------------------------------------- */


//* ---------------------------------------------------------------------------------------------- */
//*                                        start_the_rumble                                        */
//* ---------------------------------------------------------------------------------------------- */

void	print_pavimento(t_mlx *vlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT / 2 - 1;
		while (++j < SCREEN_HEIGHT)
			my_pixel_put(i, j, vlx->pavimento, vlx);
		i++;
	}
}

void	print_soffitto(t_mlx *vlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT / 2)
			my_pixel_put(i, j, vlx->soffitto, vlx);
		i++;
	}
}

int	start_the_rumble(void	*arg)
{
	t_mlx	*vlx;

	vlx = (t_mlx *)arg;

	vlx->img = mlx_new_image(vlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	vlx->address = mlx_get_data_addr(vlx->img, &vlx->bits_per_pixel, &vlx->line_length, &vlx->endian);
	print_pavimento(vlx);
	print_soffitto(vlx);
	return (1);
}

//! ---------------------------------------------------------------------------------------------- */

//? -------------------------------------------------------------------------- */
//?                                  key_stuff                                 */
//? -------------------------------------------------------------------------- */

int	quit(t_mlx *vlx)
{
	mlx_destroy_window(vlx->mlx, vlx->win);
	exit(EXIT_SUCCESS);
	return (0);
}


int	key_press(int keycode, t_mlx *vlx)
{
	if (keycode == ESC)
		quit(vlx);
	else if (keycode == W)
		vlx->key.w = 1;
	else if (keycode == S)
		vlx->key.s = 1;
	else if (keycode == A)
		vlx->key.a = 1;
	else if (keycode == D)
		vlx->key.d = 1;
	else if (keycode == LEFT)
		vlx->key.left = 1;
	else if (keycode == RIGHT)
		vlx->key.right = 1;
	return (0);
}

int	key_release(int keycode, t_mlx *vlx)
{
	if (keycode == W)
		vlx->key.w = 0;
	else if (keycode == S)
		vlx->key.s = 0;
	else if (keycode == A)
		vlx->key.a = 0;
	else if (keycode == D)
		vlx->key.d = 0;
	else if (keycode == LEFT)
		vlx->key.left = 0;
	else if (keycode == RIGHT)
		vlx->key.right = 0;
	return (0);
}


int	main(int ac, char **av)
{
	t_mlx	vlx;

	if (ac != 2)
	{
		printf("\033[0;31mERORR: invalid number of argumets\n\033[0;37m");
		return (0);
	}
	else if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
	{
		printf("\033[0;31mERROR: invalid input file format\n\033[0;37m");
		return (0);
	}
	vlx.mlx = mlx_init();
	vlx.win = mlx_new_window(vlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	parse_input(av[1], &vlx);
	init_values(&vlx);
	vlx.key.p = 1;
	mlx_loop_hook(vlx.mlx, start_the_rumble, (void *)&vlx);
	mlx_hook(vlx.win, X_EVENT_KEY_PRESS, 0, &key_press, &vlx);
	mlx_hook(vlx.win, X_EVENT_KEY_RELEASE, 0, &key_release, &vlx);
	mlx_hook(vlx.win, X_EVENT_EXIT, 0, &quit, &vlx);
	mlx_loop(vlx.mlx);
	return (0);
}