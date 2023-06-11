/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:40 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/11 10:43:19 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_color(int *color, char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		color[i] = ft_atoi(arr[i]);
		if (color[i] < 0 || color[i] > 255)
			return (0);
	}
	color[i] = 0;
	return (1);
}

int	init_colors(t_mlx *vlx)
{
	int		i;
	int		color[4];
	char	**temp;

	i = -1;
	while (vlx->rgb[++i])
	{
		temp = ft_split(vlx->rgb[i], ',');
		if (!temp)
			return (0);
		if (is_color(color, temp) == 0)
		{
			free_arr((void ***)&temp);
			return (0);
		}
		if (i == 0)
			vlx->pavimento = (color[0] << 16 | color[1] << 8 | color[2]);
		if (i == 1)
			vlx->soffitto = (color[0] << 16 | color[1] << 8 | color[2]);
		free_arr((void ***)&temp);
	}
	return (1);
}
