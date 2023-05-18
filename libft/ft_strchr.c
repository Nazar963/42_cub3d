/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:45:37 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/04 17:45:39 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*int main(void)
{
    char s[] = "fsad32";
    
    printf("originale: %s \n", strchr(s, 'a'));
    
    char sd[] = "fsad32";
    char *ptr = ft_strchr(sd, 'a');

    printf("mine: %s \n", ptr);

    return (0);
    
}*/
