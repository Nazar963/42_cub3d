/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:46:08 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/13 08:48:15 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_walls(t_mlx *vlx)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		vlx->wall[i].image = mlx_xpm_file_to_image(vlx->mlx, vlx->xpm[i],
				&(vlx->wall[i].width), &(vlx->wall[i].height));
		if (!vlx->wall[i].image)
			return (0);
		vlx->wall[i].add = (int *)mlx_get_data_addr(vlx->wall[i].image,
				&vlx->wall[i].bits_per_pixel, &vlx->wall[i].line_length,
				&vlx->wall[i].endian);
		if (!vlx->wall[i].add)
			return (0);
	}
	return (1);
}

void	set_val_1(double dir_x, double dir_y, double pla_y, t_mlx *vlx)
{
	vlx->ray.dir_x = dir_x;
	vlx->ray.dir_y = dir_y;
	vlx->ray.plane_x = 0;
	vlx->ray.plane_y = pla_y;
}

void	init_vectors(int x, int y, int *count, t_mlx *vlx)
{
	(*count)++;
	vlx->ray.pos_x = x + 0.5;
	vlx->ray.pos_y = y + 0.5;
	if (vlx->map[y][x] == 'N')
		set_val(0, -1, 0.66, vlx);
	else if (vlx->map[y][x] == 'S')
		set_val(0, 1, -0.66, vlx);
	else if (vlx->map[y][x] == 'E')
		set_val_1(1, 0, 0.66, vlx);
	else if (vlx->map[y][x] == 'W')
		set_val_1(-1, 0, -0.66, vlx);
}

int	quit_invalid_wall_path(t_mlx *vlx)
{
	free_arr((void ***)&vlx->map);
	free_arr((void ***)&vlx->rgb);
	free_arr((void ***)&vlx->xpm);
	mlx_destroy_window(vlx->mlx, vlx->win);
	mlx_destroy_display(vlx->mlx);
	free(vlx->mlx);
	write(2, "ERORR: map boarders have a gap\n", 32);
	exit(EXIT_SUCCESS);
}

int	init_values(t_mlx *vlx)
{
	if (init_walls(vlx) == 0)
		quit_invalid_wall_path(vlx);
	if (init_colors(vlx) == 0)
		return (0);
	if (validate_map(vlx) == 0)
		return (0);
	return (1);
}
