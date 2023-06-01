/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:26:07 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/01 17:58:09 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_pavimento(t_mlx *vlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT / 2;
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

void	player_rotate_left(t_mlx *vlx)
{
	double	old_direction_x;
	double	old_plane_x;

	old_direction_x = vlx->ray.dir_x;
	vlx->ray.dir_x = vlx->ray.dir_x * cos(-vlx->ray.rotate_speed)
		- vlx->ray.dir_y * sin(-vlx->ray.rotate_speed);
	vlx->ray.dir_y = old_direction_x * sin(-vlx->ray.rotate_speed)
		+ vlx->ray.dir_y * cos(-vlx->ray.rotate_speed);
	old_plane_x = vlx->ray.plane_x;
	vlx->ray.plane_x = vlx->ray.plane_x * cos(-vlx->ray.rotate_speed)
		- vlx->ray.plane_y * sin(-vlx->ray.rotate_speed);
	vlx->ray.plane_y = old_plane_x * sin(-vlx->ray.rotate_speed)
		+ vlx->ray.plane_y * cos(-vlx->ray.rotate_speed);
}

int	check_boarders_helper(int i, int j, t_mlx *vlx)
{
	if (i == 0)
	{
		while (vlx->map[i][++j])
			if (vlx->map[i][j] != '1' && vlx->map[i][j] != ' ')
				return (0);
	}
	else if (i == (strlen_arr((void **)vlx->map) - 1))
	{
		while (vlx->map[i][++j])
			if (vlx->map[i][j] != '1' && vlx->map[i][j] != ' ')
				return (0);
	}
	else
	{
		while (vlx->map[i][++j] == ' ')
			;
		if (vlx->map[i][j] != '1'
			|| vlx->map[i][ft_strlen(vlx->map[i]) - 1] != '1')
			return (0);
	}
	return (1);
}

int	check_boarders(t_mlx *vlx)
{
	int	i;
	int	j;

	i = -1;
	while (vlx->map[++i])
	{
		j = -1;
		if (!check_boarders_helper(i, j, vlx))
			return (0);
	}
	return (1);
}
