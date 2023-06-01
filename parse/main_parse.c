/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:53:29 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/01 22:13:48 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stddef.h>
#include <string.h>

int	colors(char *line, t_mlx *vlx)
{
	char	**str_split;

	str_split = ft_split(line, ' ');
	if (!str_split)
		return (0);
	if (strlen_arr((void **)str_split) != 2)
	{
		free(line);
		line = NULL;
		free_arr((void ***)&str_split);
		return (0);
	}
	if (ft_strncmp(str_split[0], "F", 1) == 0)
		vlx->rgb[0] = ft_strdup(str_split[1]);
	else if (ft_strncmp(str_split[0], "C", 1) == 0)
		vlx->rgb[1] = ft_strdup(str_split[1]);
	free_arr((void ***)&str_split);
	return (1);
}

void	walls_fill(char **str_split, t_mlx *vlx, int n)
{
	vlx->xpm[n] = ft_strdup(str_split[1]);
	if (vlx->xpm[n][ft_strlen(vlx->xpm[n]) - 1] == '\n')
		vlx->xpm[n][ft_strlen(vlx->xpm[n]) - 1] = '\0';
}

int	walls(char **line, t_mlx *vlx)
{
	char	**str_split;

	str_split = ft_split(*line, ' ');
	if (!str_split)
		return (0);
	if (strlen_arr((void **)str_split) != 2)
	{
		free(*line);
		*line = NULL;
		free_arr((void ***)&str_split);
		return (0);
	}
	if (ft_strncmp(str_split[0], "NO", 3) == 0)
		walls_fill(str_split, vlx, 0);
	else if (ft_strncmp(str_split[0], "EA", 3) == 0)
		walls_fill(str_split, vlx, 1);
	else if (ft_strncmp(str_split[0], "SO", 3) == 0)
		walls_fill(str_split, vlx, 2);
	else if (ft_strncmp(str_split[0], "WE", 3) == 0)
		walls_fill(str_split, vlx, 3);
	else if (ft_strncmp(str_split[0], "C", 2)
		&& ft_strncmp(str_split[0], "F", 2))
		return (0);
	free_arr((void ***)&str_split);
	return (1);
}

int	parse_map_and_walls_and_colors(int fd, t_mlx *vlx)
{
	char	*line;

	vlx->rgb = (char **)ft_calloc(sizeof(char *), 3);
	vlx->xpm = (char **)ft_calloc(sizeof(char *), 5);
	if (!vlx->rgb || !vlx->xpm)
		return (0);
	while (strlen_arr((void **)vlx->xpm) != 4
		|| strlen_arr((void **)vlx->rgb) != 2)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) == 0 || (ft_strlen(line) == 1 && line[0] == '\n'))
			;
		else if (walls(&line, vlx) == 0 || colors(line, vlx) == 0)
		{
			evil_line(fd);
			return (0);
		}
		free(line);
		line = NULL;
	}
	if (!map(fd, vlx))
		return (0);
	return (1);
}

int	parse_input(char *file, t_mlx *vlx)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("\033[0;31mERROR: unable to open file\n\033[0;37m");
		exit(EXIT_FAILURE);
	}
	if (parse_map_and_walls_and_colors(fd, vlx) == 0)
	{
		if (strlen_arr((void **)vlx->xpm) != 4
			|| strlen_arr((void **)vlx->rgb) != 2)
			quite_1(vlx, fd);
	}
	close(fd);
	return (1);
}
