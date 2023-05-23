/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:46:19 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/23 17:00:24 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_val(double dir_x, double dir_y, double pla_x, t_mlx *vlx)
{
	vlx->ray.dir_x = dir_x;
	vlx->ray.dir_y = dir_y;
	vlx->ray.plane_x = pla_x;
	vlx->ray.plane_y = 0;
}

int	check_char(t_mlx *vlx)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (vlx->map[i])
	{
		j = 0;
		while (vlx->map[i][j])
		{
			if (!ft_strchr(" 10NSEW", vlx->map[i][j]))
				return (0);
			if (vlx->map[i][j] == 'N' || vlx->map[i][j] == 'S'
				|| vlx->map[i][j] == 'E' || vlx->map[i][j] == 'W')
			{
				init_vectors(j, i, vlx);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static int	is_end(int index, t_mlx *vlx)
{
	int	i;

	i = index;
	i++;
	while (vlx->map[i])
	{
		if (ft_strlen(vlx->map[i]) > 0)
			return (0);
		i++;
	}
	vlx->map[i] = NULL;
	return (1);
}

static int	is_closed(int i, int j, t_mlx *vlx)
{
	if (vlx->map[i][j] == '0' || (vlx->map[i][j] != '1'
		&& vlx->map[i][j] != ' '))
	{
		if (i == 0 || !vlx->map[i + 1] || j == 0 || !vlx->map[i][j + 1])
			return (0);
		if (vlx->map[i - 1] && vlx->map[i - 1][j] && vlx->map[i - 1][j] == ' ')
			return (0);
		if (vlx->map[i + 1] && vlx->map[i + 1][j] && vlx->map[i + 1][j] == ' ')
			return (0);
		if (vlx->map[i] && vlx->map[i][j - 1] && vlx->map[i][j - 1] == ' ')
			return (0);
		if (vlx->map[i] && vlx->map[i][j + 1] && vlx->map[i][j + 1] == ' ')
			return (0);
	}
	return (1);
}

int	validate_map(t_mlx *vlx)
{
	int	i;
	int	j;

	if (strlen_arr((void **)vlx->map) < 3 || check_char(vlx) != 0)
		return (0);
	i = 0;
	while (vlx->map[i])
	{
		if (ft_strlen(vlx->map[i]) == 0)
		{
			if (is_end(i, vlx) == 0)
				return (0);
			break ;
		}
		j = 0;
		while (vlx->map[i][j])
		{
			if (is_closed(i, j, vlx) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
