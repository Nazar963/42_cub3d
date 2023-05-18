/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:25:27 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/04 12:25:31 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp1;

	temp1 = *lst;
	if (!*lst)
		return ;
	while (*lst)
	{
		temp1 = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp1;
	}
	*lst = NULL;
}
