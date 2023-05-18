/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:20:52 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/05 19:20:53 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = -1;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[++i] != '\0' && i <= len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i] == needle[j] && needle[j] != '\0' && i <= len)
			{
				i++;
				j++;
			}
		}
		if (needle[j] == '\0' && i <= len)
		{
			i -= j;
			return ((char *)&haystack[i]);
		}
		i -= j;
	}
	return (NULL);
}
/*int main(void)
{   
    // //1
    // char s[] = "say hello to my hl little friend";
    // char ss[] = "lo";
    // printf("1: %s\n", ft_strnstr(s, ss, 10));

    // //2
    // char s5[] = "say hello to my hl little friend";
    // char ss5[] = "hl";
    // printf("2: %s\n", ft_strnstr(s5, ss5, 20));
    
    // //3
    // char sa[] = "say hello to my hl little friend";
    // char ssa[] = "s";
    // printf("3: %s\n", ft_strnstr(sa, ssa, 0));
    
    // //4
    // char sw[] = "say hello to my hl little friend";
    // char ssw[] = "d";
    // printf("4: %s\n", ft_strnstr(sw, ssw, 32));

    // //5
    // char swq[] = "say hello to my hl little friend";
    // char sswq[] = "";
    // printf("5: %s\n", ft_strnstr(swq, sswq, 10));
    
    // //6
    // char sw1[] = "say hello to my hl little friend";
    // char ssw1[] = " ";
    // printf("6: %s\n", ft_strnstr(sw1, ssw1, 4));

    // //7
    // char sw13[] = "say hello to my hl little friend";
    // char ssw13[] = "'\0'";
    // printf("7: %s\n", ft_strnstr(sw13, ssw13, 20));

    // //8
    // char sw13s[] = "say hello to my hl little friend";
    // char ssw13s[] = "dsa";
    // printf("8: %s\n", ft_strnstr(sw13s, ssw13s, 6));

    return (0);
}*/