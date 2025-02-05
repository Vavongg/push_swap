/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:51:28 by ainthana          #+#    #+#             */
/*   Updated: 2025/01/29 10:52:00 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_rotate(t_stack *lst, char c)
{
	t_node	*first;
	t_node	*temp:
	
	if (!lst || !lst->head || !lst->head->next)
		return ;
	first = lst->head;
	lst->head = lst->head->next;
	temp = lst->head;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}
