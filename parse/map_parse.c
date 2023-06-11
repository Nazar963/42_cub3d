/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:13:20 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/10 15:39:05 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_checker_helper_1(char *line, t_mlx *vlx)
{
	char	**temp;

	temp = ft_realloc(vlx->map, strlen_arr((void **)vlx->map) + 2);
	if (!temp)
		return ;
	vlx->map = temp;
	vlx->map[strlen_arr((void **)vlx->map)] = ft_strdup(line);
	if (vlx->map[strlen_arr((void **)vlx->map) - 1]
		[ft_strlen(vlx->map[strlen_arr((void **)vlx->map) - 1]) - 1] == '\n')
		vlx->map[strlen_arr((void **)vlx->map) - 1]
		[ft_strlen(vlx->map[strlen_arr((void **)vlx->map) - 1]) - 1] = '\0';
}

int	map_checker(char *line, t_mlx *vlx)
{
	if ((ft_strlen(line) == 1 && line[0] == '\n') || ft_strlen(line) == 0)
		return (1);
	if (!vlx->map)
	{
		vlx->map = (char **)malloc(sizeof(char *) * 2);
		if (!vlx->map)
			return (0);
		vlx->map[0] = ft_strdup(line);
		if (vlx->map[0][ft_strlen(vlx->map[0]) - 1] == '\n')
			vlx->map[0][ft_strlen(vlx->map[0]) - 1] = '\0';
		vlx->map[1] = NULL;
	}
	else
		map_checker_helper_1(line, vlx);
	return (1);
}

int	map(int fd, t_mlx *vlx)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!map_checker(line, vlx))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

void	quite_1(t_mlx *vlx, int fd)
{
	int	i;

	i = 0;
	if (vlx->rgb[1])
	{
		free(vlx->rgb[1]);
		vlx->rgb[1] = NULL;
	}
	free_arr((void ***)&vlx->rgb);
	while (i < 4)
	{
		if (vlx->xpm[i])
		{
			free(vlx->xpm[i]);
			vlx->xpm[i] = NULL;
		}
		i++;
	}
	free_arr((void ***)&vlx->xpm);
	mlx_destroy_window(vlx->mlx, vlx->win);
	mlx_destroy_display(vlx->mlx);
	free(vlx->mlx);
	close(fd);
	write(2, "ERORR: missing color or wall texture\n", 38);
	exit(EXIT_SUCCESS);
}

void	evil_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
}
