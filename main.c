/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:32:08 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/01 18:28:33 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_mlx *vlx)
{
	int	i;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		vlx->ray.camera_x = 2 * i / (double)SCREEN_WIDTH - 1;
		vlx->ray.ray_dir_x = vlx->ray.dir_x + vlx->ray.plane_x
			* vlx->ray.camera_x;
		vlx->ray.ray_dir_y = vlx->ray.dir_y + vlx->ray.plane_y
			* vlx->ray.camera_x;
		vlx->ray.map_x = (int)vlx->ray.pos_x;
		vlx->ray.map_y = (int)vlx->ray.pos_y;
		vlx->ray.hit = 0;
		delta_distance(vlx);
		step_side_dist_x(vlx);
		step_side_dist_y(vlx);
		algorithm_dda(vlx);
		calculate_distance_perspective(vlx);
		vlx->ray.line_height = (int)(SCREEN_HEIGHT / vlx->ray.perp_wall_dist);
		calculate_draw_start_and_draw_end(vlx);
		calculate_texture_x(vlx);
		draw_vertical_texture_stripe(i, vlx);
		i++;
	}
}

int	start_the_rumble(t_mlx	*vlx)
{
	vlx->image.image = mlx_new_image(vlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	vlx->image.add = mlx_get_data_addr(vlx->image.image,
			&vlx->image.bits_per_pixel, &vlx->image.line_length,
			&vlx->image.endian);
	print_pavimento(vlx);
	print_soffitto(vlx);
	raycasting(vlx);
	vlx->ray.frame_time = 16 / 1000.0;
	vlx->ray.move_speed = vlx->ray.frame_time * 5.0;
	vlx->ray.rotate_speed = vlx->ray.frame_time * 3.0;
	mlx_put_image_to_window(vlx->mlx, vlx->win, vlx->image.image, 0, 0);
	return (1);
}

int	quit(t_mlx *vlx)
{
	free_arr((void ***)&vlx->map);
	free_arr((void ***)&vlx->rgb);
	free_arr((void ***)&vlx->xpm);
	mlx_destroy_image(vlx->mlx, vlx->image.image);
	mlx_destroy_window(vlx->mlx, vlx->win);
	mlx_destroy_display(vlx->mlx);
	free(vlx->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int keycode, t_mlx *vlx)
{
	if (keycode == ESC)
		quit(vlx);
	else if (keycode == W)
		player_move_forward(vlx);
	else if (keycode == S)
		player_move_backwards(vlx);
	else if (keycode == A)
		player_move_left(vlx);
	else if (keycode == D)
		player_move_right(vlx);
	else if (keycode == LEFT)
		player_rotate_left(vlx);
	else if (keycode == RIGHT)
		player_rotate_right(vlx);
	if (vlx->image.image)
		mlx_destroy_image(vlx->mlx, vlx->image.image);
	start_the_rumble(vlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	vlx;

	vlx.win = NULL;
	vlx.map = NULL;
	if (ac != 2)
	{
		printf("\033[0;31mERORR: invalid number of arg4umets\n\033[0;37m");
		return (0);
	}
	else if (!ft_strnstr(ft_strchr(av[1], '.'), ".cub", 4)
		|| ft_strlen(ft_strchr(av[1], '.')) != 4)
	{
		printf("\033[0;31mERROR: invalid input file format\n\033[0;37m");
		return (0);
	}
	vlx.mlx = mlx_init();
	vlx.win = mlx_new_window(vlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	parse_input(av[1], &vlx);
	if (!check_boarders(&vlx))
		new_quit(&vlx);
	init_values(&vlx);
	start_the_rumble(&vlx);
	mlx_hook(vlx.win, 2, 1L << 0, key_press, &vlx);
	mlx_hook(vlx.win, X_EVENT_EXIT, 0L, &quit, &vlx);
	mlx_loop(vlx.mlx);
}
