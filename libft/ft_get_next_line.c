/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:18:46 by naal-jen          #+#    #+#             */
/*   Updated: 2023/06/01 21:46:12 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin1(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 1;
	if (!str)
	{
		str = (char *)ft_calloc(1, sizeof(*str));
		str[0] = '\0';
	}
	j = ft_strlen(str) + ft_strlen(buff);
	if (!str || !buff)
		return (NULL);
	new_str = ft_calloc((j + 1), sizeof(*new_str));
	if (new_str == NULL)
		return (NULL);
	if (str)
		while (*str != '\0' && i++)
			*(new_str++) = *(str++);
	while (*buff != '\0')
		*(new_str++) = *(buff++);
	*new_str = '\0';
	str -= (i - 1);
	free(str);
	return (new_str - j);
}

static char	*delete(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = (char *)ft_calloc((ft_strlen(str) - i + 1), sizeof(*new_str));
	if (!new_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*process_line(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	new_str = (char *)ft_calloc((i + 2), sizeof(*new_str));
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i] != '\n' && str[i])
	{
		new_str[i] = str[i];
	}
	if (str[i] == '\n')
	{
		new_str[i] = '\n';
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*process_str(int fd, char *buff, char *str)
{
	int	num;

	num = 1;
	while (!ft_strchr(str, '\n') && num != 0)
	{
		num = read(fd, buff, BUFFER_SIZE);
		if (num == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[num] = '\0';
		str = ft_strjoin1(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*new_str;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (str != NULL)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	buff = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(*buff));
	if (!buff)
		return (NULL);
	str = process_str(fd, buff, str);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	new_str = process_line(str);
	str = delete(str);
	return (new_str);
}
// int	main(void)
// {
// 	int		fd;
// 	char	*loco;
// 	fd = 0;
// 	fd = open("read_error.txt", O_RDONLY);
// 	loco = get_next_line(fd);
// 	printf("%s", loco);
// 	free(loco);
// 	loco = get_next_line(fd);
// 	printf("%s", loco);
// 	free(loco);
// 	loco = get_next_line(fd);
// 	printf("%s", loco);
// 	free(loco);
// 	loco = get_next_line(fd);
// 	printf("%s", loco);
// 	free(loco);
// 	loco = get_next_line(fd);
// 	printf("%s", loco);
// 	free(loco);
// 	return (0);
// }
