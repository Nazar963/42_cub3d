/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:24:37 by graiolo           #+#    #+#             */
/*   Updated: 2023/06/19 16:12:10 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	valid_pos(char **mat, int y, int x)
{
	if (x > 0 && mat[y][x - 1] != 'Z' && mat[y][x - 1] != '1')
		return (0);
	if (mat[y][x + 1] != 0 && mat[y][x + 1] != 'Z' && mat[y][x + 1] != '1')
		return (0);
	if (y > 0 && mat[y - 1][x] != 'Z' && mat[y - 1][x] != '1')
		return (0);
	if (mat[y + 1] != NULL && mat[y + 1][x] != 'Z' && mat[y + 1][x] != '1')
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
			if (mat[y][x] == 'Z')
				if (!valid_pos(mat, y, x))
					return (1);
			x++;
		}
		y++;
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
			mat[y][x] = 'Z';
	}
	while (vlx->map[i] != NULL)
	{
		j = 0;
		while (vlx->map[i][j] != 0)
		{
			if (!ft_strchr("\t\n\v\f\r ", vlx->map[i][j]))
				mat[i + 1][j + 1] = vlx->map[i][j];
			j++;
		}
		i++;
	}
}

static char	**alloc(int x, int y, int tmp)
{
	char	**new;

	new = ft_calloc(y + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while ((--tmp) != -1)
	{
		new[tmp] = ft_calloc(x + 1, 1);
		if (!new[tmp])
			return (free(new), NULL);
	}
	return (new);
}

int	hole(t_mlx *vlx)
{
	int		x;
	int		y;
	int		form;
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
	new = alloc(x, y, y);
	if (!new)
		return (0);
	fill(vlx, new, x, y);
	form = valid_form(new);
	free_arr((void ***)&new);
	if (form == 1)
		return (0);
	return (1);
}
