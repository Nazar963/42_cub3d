/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:07:41 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/18 22:50:06 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen1(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr1(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin1(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 1;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(*str));
		str[0] = '\0';
	}
	j = ft_strlen1(str) + ft_strlen1(buff);
	if (!str || !buff)
		return (NULL);
	new_str = malloc((j + 1) * sizeof(*new_str));
	if (new_str == NULL)
		return (NULL);
	if (str)
		while (*str != '\0' && i++)
			*(new_str++) = *(str++);
	while (*buff != '\0')
		*(new_str++) = *(buff++);
	*new_str = '\0';
	str -= (i - 1);
	free(str);
	return (new_str - j);
}
