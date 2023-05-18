/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:53:29 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/18 22:44:19 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_checker(char *line, t_mlx *vlx)
{
	char	**temp;

	if (!vlx->map)
	{
		vlx->map = (char **)malloc(sizeof(char *) * 2);
		if (!vlx->map)
			return (0);
		vlx->map[0] = ft_strdup(line);
		vlx->map[1] = NULL;
	}
	else
	{
		temp = ft_realloc(vlx->map, strlen_arr((void **)vlx->map) + 2);
		if (!temp)
			return (0);
		vlx->map = temp;
		vlx->map[strlen_arr((void **)vlx->map)] = ft_strdup(line);
	}
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

int	colors(char *line, t_mlx *vlx)
{
	char	**str_split;

	str_split = ft_split(line, ' ');
	if (!str_split)
		return (0);
	if (strlen_arr((void **)str_split) != 2)
		return (0);
	if (ft_strncmp(str_split[0], "F", 1) == 0)
		vlx->rgb[0] = ft_strdup(str_split[1]);
	else if (ft_strncmp(str_split[0], "C", 1) == 0)
		vlx->rgb[1] = ft_strdup(str_split[1]);
	free_arr((void ***)str_split);
	return (1);
}

int	walls(char *line, t_mlx *vlx)
{
	char	**str_split;

	str_split = ft_split(line, ' ');
	if (!str_split)
		return (0);
	if (strlen_arr((void **)str_split) != 2)
		return (0);
	if (ft_strncmp(str_split[0], "NO", 3) == 0)
		vlx->xpm[0] = ft_strdup(str_split[1]);
	else if (ft_strncmp(str_split[0], "EA", 3) == 0)
		vlx->xpm[1] = ft_strdup(str_split[1]);
	else if (ft_strncmp(str_split[0], "SO", 3) == 0)
		vlx->xpm[2] = ft_strdup(str_split[1]);
	else if (ft_strncmp(str_split[0], "WE", 3) == 0)
		vlx->xpm[3] = ft_strdup(str_split[1]);
	else if (ft_strncmp(str_split[0], "C", 2) && ft_strncmp(str_split[0], "F", 2))
		return (0);
	free_arr((void ***)str_split);
	return (1);
}

int	parse_map_and_walls_and_colors(int fd, t_mlx *vlx)
{
	char	*line;

	vlx->rgb = (char **)ft_calloc(sizeof(char *), 3);
	vlx->xpm = (char **)ft_calloc(sizeof(char *), 5);
	if (!vlx->rgb || !vlx->xpm)
		return (0);
	while (strlen_arr((void **)vlx->xpm) != 4 || strlen_arr((void **)vlx->rgb) != 2)
	{
		line = get_next_line(fd);
		if (walls(line, vlx) == 0 || colors(line, vlx) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
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
	parse_map_and_walls_and_colors(fd, vlx);
	close(fd);
	return (1);
}