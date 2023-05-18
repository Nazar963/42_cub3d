/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:26:58 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/03 15:31:18 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
			return (0);
		if (nptr[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
/*int main(void)
{
    //1
    char sa[] = "       \t \r -2147fds8483647fds";
    printf("1-mine: %d\n", ft_atoi(sa));
    char s[] = "       \t \r -2147fds8483647fds";
    printf("1-original: %d\n\n", atoi(s));

    //2
    char sas[] = "       \t \r 2147483647";
    printf("2-mine: %d\n", ft_atoi(sas));
    char ss[] = "       \t \r 2147483647";
    printf("2-orignial: %d\n\n", atoi(ss));

    //3
    char saw[] = "       \t \r 2147483647";
    printf("3-mine: %d\n", ft_atoi(saw));
    char sw[] = "       \t \r 2147483647";
    printf("3-original: %d\n\n", atoi(sw));

    //4
    char saq[] = "+2147483647";
    printf("4-mine: %d\n", ft_atoi(saq));
    char sq[] = "+2147483647";
    printf("4-original: %d\n\n", atoi(sq));

    //5
    char sae[] = "-2147483648";
    printf("5-mine: %d\n", ft_atoi(sae));
    char se[] = "-2147483648";
    printf("5-original: %d\n\n", atoi(se));

    //6
    char sar[] = "-0";
    printf("6-mine: %d\n", ft_atoi(sar));
    char sr[] = "-0";
    printf("6-original: %d\n\n", atoi(sr));

    //7
    char sat[] = "       \t \r g -2147fds8483647fds";
    printf("7-mine: %d\n", ft_atoi(sat));
    char st[] = "  \t   \r    g    -2147fds483647few4f";
    printf("7-original: %d\n\n", atoi(st));

    //8
    char say[] = "       \t \r -+2147fds8483647fds";
    printf("8-mine: %d\n", ft_atoi(say));
    char sy[] = "       \t \r    -+2147fds483647few4f";
    printf("8-original: %d\n\n", atoi(sy));

    //9
    char say9[] = "       \t \r + 2147fds8483647fds";
    printf("9-mine: %d\n", ft_atoi(say9));
    char sy9[] = "       \t \r    + 2147fds483647few4f";
    printf("9-original: %d\n\n", atoi(sy9));

    //10
    char say9a[] = "0";
    printf("10-mine: %d\n", ft_atoi(say9a));
    char sy9a[] = "0";
    printf("10-original: %d\n\n", atoi(sy9a));

    return (0);
}*/
