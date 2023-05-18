/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:31:46 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/03 15:31:48 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_isalnum(int c)
{
	unsigned char	v;

	v = (unsigned char)c;
	if ((v >= 'a' && v <= 'z') || (v >= 'A' && v <= 'Z')
		|| (v >= '0' && v <= '9'))
		return (1);
	else
		return (0);
}
/*int main(void)
{
    //1
    char a1 = '3';
    printf("1-mine: %d\n", ft_isalnum(a1));
    char aa1 = '3';
    printf("1-original: %d\n\n", isalnum(aa1));
    
    //2
    char a2 = 'b';
    printf("2-mine: %d\n", ft_isalnum(a2));
    char aa2 = 'b';
    printf("2-original: %d\n\n", isalnum(aa2));
    
    //3
    char a3 = 'E';
    printf("3-mine: %d\n", ft_isalnum(a3));
    char aa3 = 'E';
    printf("3-original: %d\n\n", isalnum(aa3));
    
    //4
    char a4 = '&';
    printf("4-mine: %d\n", ft_isalnum(a4));
    char aa4 = '&';
    printf("4-original: %d\n\n", isalnum(aa4));
    
    //5
    char a5 = '/';
    printf("5-mine: %d\n", ft_isalnum(a5));
    char aa5 = '/';
    printf("5-original: %d\n\n", isalnum(aa5));

    return (0);
}*/
