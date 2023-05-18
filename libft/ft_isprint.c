/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:32:39 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/03 15:32:40 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*int main(void)
{
    //1
    int a1 = 32;
    printf("1-mine: %d\n", ft_isprint(a1));
    int aa1 = 32;
    printf("1-original: %d\n\n", isprint(aa1));
    
    //2
    int a2 = 31;
    printf("2-mine: %d\n", ft_isprint(a2));
    int aa2 = 31;
    printf("2-original: %d\n\n", isprint(aa2));
    
    //3
    int a3 = 126;
    printf("3-mine: %d\n", ft_isprint(a3));
    int aa3 = 126;
    printf("3-original: %d\n\n", isprint(aa3));
    
    //4
    char a4 = 127;
    printf("4-mine: %d\n", ft_isprint(a4));
    char aa4 = 127;
    printf("4-original: %d\n\n", isprint(aa4));
    
    //5
    char a5 = 100;
    printf("5-mine: %d\n", ft_isprint(a5));
    char aa5 = 100;
    printf("5-original: %d\n\n", isprint(aa5));

    return (0);
}*/
