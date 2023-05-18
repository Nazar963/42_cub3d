/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:35:13 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/10 15:37:42 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	count_digits(long int n)
{
	int	i;

	if (n < 0)
		i = 1;
	else
		i = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			i;
	long int	nbr;

	i = count_digits(n);
	nbr = n;
	ptr = (char *)malloc((i + 1) * sizeof(*ptr));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	if (nbr == 0)
		ptr[0] = '0';
	if (nbr < 0)
	{
		ptr[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		ptr[--i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (ptr);
}

// int main(void)
// {
// 	printf(" 0\n\"%s\"\n\n", ft_itoa(-9));
// 	// printf(" 0\n\"%s\"\n\n", ft_itoa(0));
// 	// printf(" -0\n\"%s\"\n\n", ft_itoa(-0));
// 	// printf(" 123\n\"%s\"\n\n", ft_itoa(123));
// 	// printf(" -123\n\"%s\"\n\n", ft_itoa(-123));
// 	// printf(" -321\n\"%s\"\n\n", ft_itoa(-321));
// 	// printf(" -12345\n\"%s\"\n\n", ft_itoa(-12345));
// 	// printf(" 123456789\n\"%s\"\n\n", ft_itoa(123456789));
// 	// printf(" -123456789\n\"%s\"\n\n", ft_itoa(-123456789));
// 	// printf(" 2147483647\n\"%s\"\n\n", ft_itoa(2147483647));
// 	// printf(" -2147483648\n\"%s\"\n\n", ft_itoa(-2147483648));
// 	// printf(" 0000000000\n\"%s\"\n\n", ft_itoa(0000000000));
// 	// printf(" -214748-3648\n\"%s\"\n\n", ft_itoa(-214748-3648));
// 	// printf(" -2+147483648\n\"%s\"\n\n", ft_itoa(-2+147483648));
// 	return (0);
// }