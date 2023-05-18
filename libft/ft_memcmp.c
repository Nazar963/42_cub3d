/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:04:49 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/04 15:04:52 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;
	int				char_compare;

	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	char_compare = 0;
	if (s1 == s2)
		return (char_compare);
	while (n > 0)
	{
		if (*p != *q)
		{
			if (*p > *q)
				char_compare = 1;
			else
				char_compare = -1;
			break ;
		}
		n--;
		p++;
		q++;
	}
	return (char_compare);
}
/*int main()
{
    int ret = 0;
    //If s1 and s2 equal
    ret = ft_memcmp("abc","abc",2);
    printf("mine = %d\n",ret);
    //if first char of s1 is large to s2
    ret = ft_memcmp("bca","abc",2);
    printf("mine = %d\n",ret);
    //if first char of s1 is small to s2
    ret = ft_memcmp("abc","bca",2);
    printf("mine = %d\n",ret);

    int bret = 0;
    //If s1 and s2 equal
    bret = memcmp("abc","abc",2);
    printf("\nog = %d\n",bret);
    //if first char of s1 is large to s2
    bret = memcmp("bca","abc",2);
    printf("og = %d\n",bret);
    //if first char of s1 is small to s2
    bret = memcmp("abc","bca",2);
    printf("og = %d\n",bret);
    return 0;
}*/
