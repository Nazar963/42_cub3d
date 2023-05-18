/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:49:07 by coder             #+#    #+#             */
/*   Updated: 2022/08/05 19:20:26 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*int main(void)
{
    //1
    char s1[] = "say hello to my little friend";
    char s2[] = "say hello to my little friend";
    printf("1_mine:     %d\n", ft_strncmp(s1, s2, 30));
    char s12[] = "say hello to my little friend";
    char s23[] = "say hello to my little friend";
    printf("1_original: %d\n\n", strncmp(s12, s23, 30));
    
    //2
    char as1[] = "say hello to my little frient";
    char as2[] = "say hello to my little friend";
    printf("2_mine:     %d\n", ft_strncmp(as1, as2, 31));
    char as12[] = "say hello to my little frient";
    char as23[] = "say hello to my little friend";
    printf("2_original: %d\n\n", strncmp(as12, as23, 31));
    
    //3
    char a3s1[] = "say hello to my little friend";
    char a3s2[] = "say hello to my little frient";
    printf("3_mine:     %d\n", ft_strncmp(a3s1, a3s2, 30));
    char a3s12[] = "say hello to my little friend";
    char a3s23[] = "say hello to my little frient";
    printf("3_original: %d\n\n", strncmp(a3s12, a3s23, 30));

    //4
    char sa3s1[] = "asay hello to my little friend";
    char sa3s2[] = "say hello to my little friend";
    printf("4_mine:     %d\n", ft_strncmp(sa3s1, sa3s2, 30));
    char sa3s12[] = "asay hello to my little friend";
    char sa3s23[] = "say hello to my little friend";
    printf("4_original: %d\n\n", strncmp(sa3s12, sa3s23, 30));

    //5
    char s1a[] = "say hello to my little friend";
    char s2a[] = "say hello to my little";
    printf("5_mine:     %d\n", ft_strncmp(s1a, s2a, 25));
    char s12s[] = "say hello to my little friend";
    char s23s[] = "say hello to my little";
    printf("5_original: %d\n\n", strncmp(s12s, s23s, 25));

    //6
    char s1ad[] = "say hello to my";
    char s2ad[] = "say hello to my little";
    printf("6_mine:     %d\n", ft_strncmp(s1ad, s2ad, 20));
    char s12sd[] = "say hello to my";
    char s23sd[] = "say hello to my little";
    printf("6_original: %d\n\n", strncmp(s12sd, s23sd, 20));

    //7
    char s1ads[] = "say hello to my";
    char s2ads[] = "";
    printf("7_mine:     %d\n", ft_strncmp(s1ads, s2ads, 5));
    char s12sds[] = "say hello to my";
    char s23sds[] = "";
    printf("7_original: %d\n\n", strncmp(s12sds, s23sds, 5));

    //8
    char s1ads1[] = "say hello to my";
    char s2ads1[] = "'\0'";
    printf("8_mine:     %d\n", ft_strncmp(s1ads1, s2ads1, 35));
    char s12sds1[] = "say hello to my";
    char s23sds1[] = "'\0'";
    printf("8_original: %d\n\n", strncmp(s12sds1, s23sds1, 35));

    return (0);
}*/