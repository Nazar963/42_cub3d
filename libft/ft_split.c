/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:45:28 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/10 15:12:40 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>

static	char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static	char	*string_length(char const *str, char c, int i)
{
	int		j;
	char	*string;

	j = 0;
	string = (char *)malloc((ft_strlen(str) + 1) * sizeof(*string));
	if (!string)
		return (NULL);
	while (str[i] == c)
		i++;
	while (str[i])
	{
		*string = str[i];
		if (str[i + 1] == c || str[i + 1] == '\0')
		{
			string++;
			j++;
			*string = '\0';
			return (string - j);
		}
		string++;
		j++;
		i++;
	}
	return (0);
}

static	int	count_strings(char const *str, char c)
{
	int	i;
	int	count;
	int	def;

	i = 0;
	count = 0;
	def = 1;
	while (str[i])
	{
		if (str[i] == c && def == 0)
		{
			def = 1;
		}
		if (str[i] != c && def == 1)
		{
			count++;
			def = 0;
		}
		i++;
	}
	return (count);
}

static	char	**creat_splits(char const *s, char **split, char c)
{
	int		i;
	int		len;
	int		num_of_strings;
	char	*string;
	int		count;

	i = 0;
	count = 0;
	num_of_strings = count_strings(s, c);
	while (i < num_of_strings)
	{
		while (s[count] == c && s[count])
			count++;
		string = string_length(s, c, count);
		len = ft_strlen(string);
		split[i] = (char *)malloc(len + 1);
		if (!split[i])
			return (NULL);
		ft_strcpy(split[i], string);
		count += len;
		i++;
		free(string);
		string = NULL;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	**flip;
	int		num_of_strings;

	num_of_strings = count_strings(s, c);
	split = (char **)malloc((num_of_strings + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[num_of_strings] = NULL;
	split = creat_splits(s, split, c);
	if (split == NULL)
	{
		flip = split;
		while (*flip)
		{
			free (*flip);
			flip++;
		}
		free (split);
		split = NULL;
	}
	return (split);
}
// int	main(void)
// {
// 	char s[] = "";
//   	char **split_strings = ft_split(s, 'a');
// 	for (int i = 0; i < 11; i++)
// 	{
// 		printf("%s\n", split_strings[i]);
// 	}
// 	printf("***************************\n");
// 	// char s[] = "  To  be  or  not  to  be  j  that   is  the  question  ";
//   	// char **split_strings = ft_split(s, ' ');
// 	// for (int i = 0; i < 11; i++)
// 	// 	printf("%s\n", split_strings[i]);
// 	// printf("***************************\n");
// 	// char s2[] = "Hello there";
//   	// char **split_strings2 = ft_split(s2, ' ');
// 	// for (int i = 0; i < 2; i++)
// 	// 	printf("%s\n", split_strings2[i]);
// 	// printf("***************************\n");
// 	// char s3[] = ",,, ,,Hello,there,you,,, ,";
//   	// char **split_strings3 = ft_split(s3, ',');
// 	// for (int i = 0; i < 5; i++)
// 	// 	printf("%s\n", split_strings3[i]);
// 	// printf("***************************\n");
// 	// char s4[] = "   b  Hello there you   b ";
//   	// char **split_strings4 = ft_split(s4, ' ');
// 	// for (int i = 0; i < 5; i++)
// 	// 	printf("%s\n", split_strings4[i]);
// 	return (0);
// }