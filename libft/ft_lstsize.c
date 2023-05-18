/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:21:03 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/04 14:21:05 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*fun;
	int		i;

	if (!lst)
	{
		return (0);
	}
	i = 1;
	fun = lst;
	while (fun->next != NULL)
	{
		fun = fun->next;
		i++;
	}
	return (i);
}
