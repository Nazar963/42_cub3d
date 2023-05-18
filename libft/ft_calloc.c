/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:30:30 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/03 15:31:40 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	if (size && nmemb > 2147483647 / size)
		return (NULL);
	p = (char *)malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return (p);
}
/*int main(void)
{
    char str[] = "hello";
	printf("before: %s\n", str);
    ft_calloc(ft_strlen(str), sizeof(*str));
    printf("my: %s\n\n", str);
    
    char loco[] = "hello";
    printf("before: %s\n", loco);
	calloc(ft_strlen(loco), sizeof(*loco));
    printf("og: %s\n", loco);
}*/
