/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/09 19:22:53 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*nsrc;
	char	*ndest;
	size_t	i;

	nsrc = (char *)src;
	ndest = (char *)dest;
	if (n == 0 || dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (dest);
}
/*int	main(void)
{
	char deso[50];
	char loco[] = "zy\0xw\0vu\0\0tsr";
	ft_memcpy(deso, loco, 11);
	printf("%s\n\n", deso);

	char		adeso[50];
	const char	aloco[] = "zy\0xw\0vu\0\0tsr";
	memcpy(adeso, aloco, 11);
	printf("%s\n\n", adeso);
	return (0);
}*/