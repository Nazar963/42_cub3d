/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:40 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/18 10:34:03 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_color(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		if (ft_atoi(arr[i]) < 0 || ft_atoi(arr[i]) > 255)
			return (0);
	}
	return (1);
}

int	init_colors(t_mlx *vlx)
{
	int		i;
	char	**temp;

	i = -1;
	while (vlx->rgb[++i])
	{
		temp = ft_split(vlx->rgb[i], ',');
		if (!temp)
			return (0);
		if (is_color(temp) == 0)
		{
			free_arr((void ***)&temp);
			return (0);
		}
		if (i == 0)
			vlx->pavimento = (ft_atoi(temp[0]) << 16
					| ft_atoi(temp[1]) << 8 | ft_atoi(temp[2]));
		if (i == 1)
			vlx->soffitto = (ft_atoi(temp[0]) << 16
					| ft_atoi(temp[1]) << 8 | ft_atoi(temp[2]));
		free_arr((void ***)&temp);
	}
	return (1);
}

void	quite_4(char *line, int fd, t_mlx *vlx)
{
	free(line);
	evil_line(fd);
	close(fd);
	if (vlx->rgb)
		free_arr((void ***)&vlx->rgb);
	if (vlx->xpm)
		free_arr((void ***)&vlx->xpm);
	if (vlx->map)
		free_arr((void ***)&vlx->map);
	mlx_destroy_window(vlx->mlx, vlx->win);
	mlx_destroy_display(vlx->mlx);
	free(vlx->mlx);
	write(2, "ERORR: Unable to allocate memory\n", 34);
	exit(EXIT_SUCCESS);
}
