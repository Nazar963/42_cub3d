/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:27:46 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/06 21:27:48 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

static int	first_trim(char const *s1, char const *set, size_t j, int n)
{
	n = 0;
	while (s1[n])
	{
		if (s1[n] != set[j])
		{
			j = 0;
			while (set[j] != s1[n])
			{
				if (set[j] == '\0')
				{
					return (n);
				}
				j++;
			}
		}
		while (s1[n] == set[j])
		{
			n++;
		}
		j++;
	}
	return (n);
}

static int	last_trim(char const *s1, char const *set, size_t j, int fin)
{
	fin = ft_strlen(s1);
	while (fin)
	{
		if (s1[fin] != set[j])
		{
			j = 0;
			while (set[j] != s1[fin])
			{
				if (set[j] == '\0')
				{
					return (fin);
				}
				j++;
			}
		}
		while (s1[fin] == set[j])
		{
			fin--;
		}
		j++;
	}
	return (fin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	size_t	n;
	size_t	fin;
	size_t	len;

	j = 0;
	n = 0;
	fin = 0;
	len = ft_strlen(s1);
	n = first_trim(s1, set, j, n);
	s1 += n;
	fin = last_trim(s1, set, j, fin);
	if (n == len)
		return (ft_substr(s1, 0, 0));
	else
		return (ft_substr(s1, 0, fin + 1));
}

/*int main(void){
	// const char *a1 = "bed";
	// printf("1: %s\n", ft_strtrim("bedhelbedlobed", a1));
	// const char *a2 = "bed";
	// printf("2: %s\n", ft_strtrim("bedbedhelbedlobedbed", a2));
	// const char *a4 = "v v v";
	// printf("4: %s\n", ft_strtrim("v vhellov v", a4));
	// const char *a5 = "1234567";
	// printf("5: %s\n", ft_strtrim("1234bedhelbedlobed1234567", a5));
	// const char *a6 = "g";
	// printf("6: %s\n", ft_strtrim("gbgegdghgeglgbgegdglgogbgegdg", a6));
}*/