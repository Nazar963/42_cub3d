/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:48:50 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/18 22:28:29 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/// @brief it will create a new copy of pointer with the same values but of size size
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

/// @brief this function will return the number of sub arrays presented in an array
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


/// @brief this function will free all sub arrays setting them to NULL and then freeing and setting up the array to NULL
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
