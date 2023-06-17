/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:32:08 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/17 18:58:46 by naal-jen         ###   ########.fr       */
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
		calculate_the_distance_to_the_next_x_or_y_side(vlx);
		calculate_the_step_and_initial_side_distance_x(vlx);
		calculate_the_step_and_initial_side_distance_y(vlx);
		perform_digital_differential_analysis(vlx);
		calculate_distance_projected_on_camera_direction(vlx);
		vlx->ray.line_height = (int)(SCREEN_HEIGHT / vlx->ray.perp_wall_dist);
		calculate_draw_start_and_draw_end(vlx);
		calculate_texture_x(vlx);
		draw_stripe_color_pixel(i, vlx);
		i++;
	}
}

int	start_the_rumble(t_mlx	*vlx)
{
	vlx->image.image = mlx_new_image(vlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	vlx->image.add = mlx_get_data_addr(vlx->image.image,
			&vlx->image.bits_per_pixel, &vlx->image.line_length,
			&vlx->image.endian);
	print_pavimento_soffitto(vlx);
	raycasting(vlx);
	mlx_put_image_to_window(vlx->mlx, vlx->win, vlx->image.image, 0, 0);
	return (1);
}

int	quit(t_mlx *vlx)
{
	int	i;

	i = -1;
	free_arr((void ***)&vlx->map);
	free_arr((void ***)&vlx->rgb);
	free_arr((void ***)&vlx->xpm);
	mlx_destroy_image(vlx->mlx, vlx->image.image);
	while (++i < 4)
		mlx_destroy_image(vlx->mlx, vlx->wall[i].image);
	mlx_destroy_window(vlx->mlx, vlx->win);
	mlx_destroy_display(vlx->mlx);
	free(vlx->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int key, t_mlx *vlx)
{
	if (key == ESC)
		quit(vlx);
	else if (key == W)
		move_forward(vlx);
	else if (key == S)
		move_backwards(vlx);
	else if (key == A)
		move_left(vlx);
	else if (key == D)
		move_right(vlx);
	else if (key == LEFT)
		rotate_left(vlx);
	else if (key == RIGHT)
		rotate_right(vlx);
	if (vlx->image.image)
		mlx_destroy_image(vlx->mlx, vlx->image.image);
	start_the_rumble(vlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	vlx;

	vlx.map = NULL;
	if (ac != 2)
	{
		printf("\033[0;31mERORR: invalid number of argumets\n\033[0;37m");
		return (0);
	}
	else if (!ft_strnstr(ft_strchr(av[1], '.'), ".cub", 4)
		|| ft_strlen(ft_strchr(av[1], '.')) != 4)
	{
		printf("\033[0;31mERROR: invalid input file format\n\033[0;37m");
		return (0);
	}
	parse_input(av[1], &vlx);
	if (init_values(&vlx) == 0)
		new_quit_2(&vlx);
	start_the_rumble(&vlx);
	mlx_hook(vlx.win, 2, 1L << 0, key_press, &vlx);
	mlx_hook(vlx.win, X_EVENT_EXIT, 0L, &quit, &vlx);
	mlx_loop(vlx.mlx);
}
