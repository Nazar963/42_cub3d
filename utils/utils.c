/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:48:50 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/01 21:55:59 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/// @brief create a new copy of pointer with the same values but of size size
/// @param pointer is the old pointer to be modified
/// @param size is the size to be applicated
/// @return the new copy with the new allocation
char	**ft_realloc(char **pointer, int size)
{
	int		i;
	char	**new_pointer;

	i = 0;
	new_pointer = (char **)malloc(sizeof(char *) * size);
	if (!new_pointer)
		return (NULL);
	while (pointer[i])
	{
		new_pointer[i] = pointer[i];
		i++;
	}
	new_pointer[i] = NULL;
	new_pointer[i + 1] = NULL;
	free(pointer);
	return (new_pointer);
}

/// @brief return the number of sub arrays presented in an array
/// @param arr a double pointer variable
/// @return the number of sub arrays
int	strlen_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/// @brief free all sub arrays setting them to NULL and 
///			then freeing and setting up the array to NULL
/// @param &arr the address of a double pointer variable
void	free_arr(void ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	my_pixel_put(int x, int y, int color, t_mlx *vlx)
{
	char	*dst;

	dst = vlx->image.add
		+ (y * vlx->image.line_length + x * (vlx->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	new_quit(t_mlx *vlx)
{
	free_arr((void ***)&vlx->map);
	free_arr((void ***)&vlx->rgb);
	free_arr((void ***)&vlx->xpm);
	mlx_destroy_window(vlx->mlx, vlx->win);
	mlx_destroy_display(vlx->mlx);
	free(vlx->mlx);
	write(2, "ERORR: map boarders have a gap\n", 32);
	exit(EXIT_SUCCESS);
}
