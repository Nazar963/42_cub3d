/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:49:07 by coder             #+#    #+#             */
/*   Updated: 2022/08/06 21:28:04 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_tolower(int c)
{
	if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
	{
		c += 32;
	}
	return (c);
}
/*int main(void)
{
      char s = 'A';
      printf("%c\n", ft_tolower(s));
      char s1 = 'A';
      printf("%c\n\n", tolower(s1));

      char s2 = 'Z';
      printf("%c\n", ft_tolower(s2));
      char s12 = 'Z';
      printf("%c\n\n", tolower(s12));
      
      char s3 = '3';
      printf("%c\n", ft_tolower(s3));
      char s13 = '3';
      printf("%c\n\n", tolower(s13));

      char s4 = 'g';
      printf("%c\n", ft_tolower(s4));
      char s14 = 'g';
      printf("%c\n\n", tolower(s14));

      return (0);
}*/
