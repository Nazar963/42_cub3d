/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:46:19 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/18 10:31:51 by naal-jen         ###   ########.fr       */
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
	size_t	i;
	size_t	j;
	int		count;

	i = -1;
	count = 0;
	while (vlx->map[++i])
	{
		j = -1;
		while (vlx->map[i][++j])
		{
			if (!ft_strchr("\t\n\v\f\r 10NSEW", vlx->map[i][j]))
				return (0);
			if (!ft_strchr(" 10\t\n\v\f\r", vlx->map[i][j]))
			{
				if ((j > ft_strlen(vlx->map[i + 1]))
					|| (j > ft_strlen(vlx->map[i - 1])))
					return (0);
				init_vectors(j, i, &count, vlx);
			}
		}
	}
	if (count != 1)
		return (0);
	return (count);
}

int	validate_map(t_mlx *vlx)
{
	int	i;

	if (strlen_arr((void **)vlx->map) < 3 || check_char(vlx) == 0)
		return (0);
	i = -1;
	while (vlx->map[++i])
		if (ft_strlen(vlx->map[i]) == 0)
			return (0);
	return (1);
}
