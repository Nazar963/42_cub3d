/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:49:07 by coder             #+#    #+#             */
/*   Updated: 2022/08/06 21:28:09 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_toupper(int c)
{
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
	{
		c -= 32;
	}
	return (c);
}
/*int main(void)
{
      char s = 'a';
      printf("%c\n", ft_toupper(s));
      char s1 = 'a';
      printf("%c\n\n", toupper(s1));

      char s2 = 'z';
      printf("%c\n", ft_toupper(s2));
      char s12 = 'z';
      printf("%c\n\n", toupper(s12));
      
      char s3 = '3';
      printf("%c\n", ft_toupper(s3));
      char s13 = '3';
      printf("%c\n\n", toupper(s13));

      char s4 = 'G';
      printf("%c\n", ft_toupper(s4));
      char s14 = 'G';
      printf("%c\n\n", toupper(s14));

      return (0);
}*/
