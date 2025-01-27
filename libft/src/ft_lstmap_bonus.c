/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:06:28 by ainthana          #+#    #+#             */
/*   Updated: 2024/11/26 17:51:15 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	t_list	*temp;

	if (!lst)
		return (NULL);
	first = ft_lstnew(f(lst->content));
	temp = lst->next;
	while (temp)
	{
		new = ft_lstnew(f(temp->content));
		if (!new)
		{
			ft_lstclear(&first, (*del));
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		temp = temp->next;
	}
	return (first);
}
