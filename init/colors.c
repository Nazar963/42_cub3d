/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:40 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/23 16:58:30 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned long	rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

int	*is_color(char **arr)
{
	int	i;
	int	*rgb;

	i = 0;
	rgb = (int *)malloc(4 * sizeof(int));
	if (!rgb)
		return (0);
	while (arr[i])
	{
		rgb[i] = ft_atoi(arr[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (0);
		i++;
	}
	rgb[i] = 0;
	return (rgb);
}

void	convert_rgb(int *rgb, int i, t_mlx *vlx)
{
	unsigned long	temp;

	if (i == 0)
	{
		temp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		vlx->pavimento = temp;
	}
	if (i == 1)
	{
		temp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		vlx->soffitto = temp;
	}
}

int	init_colors(t_mlx *vlx)
{
	int		i;
	int		*rgb;
	char	**temp;

	i = 0;
	while (vlx->rgb[i])
	{
		temp = ft_split(vlx->rgb[i], ',');
		if (!temp)
			return (0);
		rgb = is_color(temp);
		if (!rgb)
		{
			free(rgb);
			return (0);
		}
		convert_rgb(rgb, i, vlx);
		free_arr((void ***)&temp);
		free(rgb);
		i++;
	}
	return (1);
}
