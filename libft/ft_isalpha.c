/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:32:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/09 17:36:50 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
/*int main(void)
{
    //1
    char a1 = 'a';
    printf("1-mine: %d\n", ft_isalpha(a1));
    char aa1 = 'a';
    printf("1-original: %d\n\n", isalpha(aa1));
    
    //2
    char a2 = 'z';
    printf("2-mine: %d\n", ft_isalpha(a2));
    char aa2 = 'z';
    printf("2-original: %d\n\n", isalpha(aa2));
    
    //3
    char a3 = 'A';
    printf("3-mine: %d\n", ft_isalpha(a3));
    char aa3 = 'A';
    printf("3-original: %d\n\n", isalpha(aa3));
    
    //4
    char a4 = 'Z';
    printf("4-mine: %d\n", ft_isalpha(a4));
    char aa4 = 'Z';
    printf("4-original: %d\n\n", isalpha(aa4));
    
    //5
    char a5 = '2';
    printf("5-mine: %d\n", ft_isalpha(a5));
    char aa5 = '2';
    printf("5-original: %d\n\n", isalpha(aa5));

    return (0);
}*/
