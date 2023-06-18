/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:24:37 by graiolo           #+#    #+#             */
/*   Updated: 2023/06/18 20:16:28 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	valid_pos(char **mat, int y, int x)
{
	if (x > 0 && mat[y][x - 1] != 'E' && mat[y][x - 1] != '1')
		return (0);
	if (mat[y][x + 1] != 0 && mat[y][x + 1] != 'E' && mat[y][x + 1] != '1')
		return (0);
	if (y > 0 && mat[y - 1][x] != 'E' && mat[y - 1][x] != '1')
		return (0);
	if (mat[y + 1] != NULL && mat[y + 1][x] != 'E' && mat[y + 1][x] != '1')
		return (0);
	return (1);
}

static int	valid_form(char **mat)
{
	int	x;
	int	y;

	y = 0;
	while (mat[y] != NULL)
	{
		x = 0;
		while (mat[y][x] != 0)
		{
			if (mat[y][x] == 'E')
				if (!valid_pos(mat, y, x))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

static void	fill(t_mlx *vlx, char **mat, int x, int y)
{
	int	tmp;
	int	i;
	int	j;

	tmp = x;
	i = 0;
	while (--y != -1)
	{
		x = tmp;
		while (--x != -1)
			mat[y][x] = 'E';
	}
	while (vlx->map[i] != NULL)
	{
		j = 0;
		while (vlx->map[i][j] != 0)
		{
			if (ft_isspace(vlx->map[i][j]) != 1)
				mat[i + 1][j + 1] = vlx->map[i][j];
			j++;
		}
		i++;
	}
}

int	hole(t_mlx *vlx)
{
	int		x;
	int		y;
	int		tmp;
	char	**new;

	y = 0;
	x = 0;
	while (vlx->map[y] != NULL)
	{
		if (x < (int)ft_strlen(vlx->map[y]))
			x = ft_strlen(vlx->map[y]);
		y++;
	}
	x += 2;
	y += 2;
	tmp = y;
	new = calloc(y + 1, sizeof(char *));
	while ((--tmp) != -1)
		new[tmp] = ft_calloc(x + 1, 1);
	tmp = y;
	fill(vlx, new, x, y);
	if (valid_form(new) == 1)
		return (free_arr(&new), 0);
	return (free_arr(&new), 1);
}
