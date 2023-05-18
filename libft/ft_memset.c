/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:44:56 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/10 15:13:37 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	char			car;

	car = (char)c;
	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = car;
		p++;
		n--;
	}
	return (s);
}

// int main(void)
// {
// 	// char str[5] = "hello";
// 	// char br[5] = "hello";   
// 	// ft_memset(str + 1, '*', 3);
// 	// printf("my: %s\n", str);
// 	// memset(str + 1, '*', 3);
// 	// printf("og: %s\n", str);
// 	// ft_memset(br, '*', 1);
// 	// printf("my: %s\n", br);
// 	// memset(br, '*', 1);
// 	// printf("og: %s\n", br);
// 	char tab[100];
// 	memset(tab, 0, 100);
// 	// printf("og: %s\n", tab);
// 	// ft_memset(tab, 'A', 0);
// 	// printf("og: %s\n", tab);
// 	// memset(tab, 'A', 0);
// 	// printf("og: %s\n", tab);
// 	ft_memset(NULL, 'A', 42);
// 	printf("og: %s\n", tab);
// 	memset(NULL, 'A', 42);
// 	printf("og: %s\n", tab);
// }