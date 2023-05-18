/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:30:06 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/03 15:30:13 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*int main(void)
{
    char str[] = "hello";
	printf("before: %s\n", str);
    ft_bzero(str, 2);
    printf("my: %s\n", str);
    
    char loco[] = "hello";
    printf("before: %s\n", loco);
	bzero(loco, 2);
    printf("og: %s\n", loco);
}*/