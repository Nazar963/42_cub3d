/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:46:08 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/21 13:58:06 by naal-jen         ###   ########.fr       */
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

void	fill_wall(int i, t_mlx *vlx)
{
	int		x;
	int		y;

	y = -1;
	while (++y < vlx->wall[i].height)
	{
		x = -1;
		while (++x < vlx->wall[i].width)
		{
			vlx->wall_dim[i][vlx->wall[i].height * y + x] = vlx->wall[i].add[vlx->wall[i]. height * y + x];
		}
	}
}

int	init_walls(t_mlx *vlx)
{
	int		i;
	void	*temp;
	int		*address;

	i = 0;
	while (i < 4)
	{
		temp = mlx_xpm_file_to_image(vlx->mlx, vlx->xpm[i],
			&(vlx->wall[i].width), &(vlx->wall[i].height));
		vlx->wall[i].image = temp;
		if (!vlx->wall[i].image)
			return (0);
		address = (int *)mlx_get_data_addr(vlx->wall[i].image,
			&vlx->wall[i].bits_per_pixel, &vlx->wall[i].line_length,
			&vlx->wall[i].endian);
		vlx->wall[i].add = address;
		if (!vlx->wall[i].add)
			return (0);
		fill_wall(i, vlx);
		mlx_destroy_image(vlx->mlx, vlx->wall[i].image);
		i++;
	}
	return (1);
}

void	init_values(t_mlx *vlx)
{
	if (init_walls(vlx) == 0)
		return ;
	if (init_colors(vlx) == 0)
		return ;
}
