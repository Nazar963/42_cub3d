/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:46:22 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/04 19:41:40 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	len;
	char	*ptr;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(len * sizeof(*ptr));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
/*int main(void)
{
	char	s1[] = "hello";
	char	s2[] = " you";
	printf("%s\n", ft_strjoin(s1, s2));
	
	// char	as1[] = "lorem ipsum";
	// char	as2[] = "dolor sit amet";
	// as1[0] = '\0';
	// printf("%s\n", ft_strjoin(as1, as2));
	
	// char	ss1[] = "lorem ipsum";
	// char	ss2[] = "dolor sit amet";
	// ss2[0] = '\0';
	// printf("%s\n", ft_strjoin(ss1, ss2));
	
	// char	ws1[] = "lorem ipsum";
	// char	ws2[] = "dolor sit amet";
	// ws1[0] = '\0';
	// ws2[0] = '\0';
	// printf("%s\n", ft_strjoin(ws1, ws2));

	return (0);
}*/