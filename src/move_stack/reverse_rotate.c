/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:51:08 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/10 19:06:30 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_reverse_rotate(t_stack *lst, char c)
{
	t_node	*last;
	t_node	*temp;

	if (!lst || !lst->head || !lst->head->next)
		return ;
	last = lst->head;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = lst->head;
	lst->head = last;
	ft_printf("rr%c\n", c);
}

void	ft_reverse_rotate_both(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a, 'a');
	ft_reverse_rotate(b, 'b');
	ft_printf("rrr\n");
}
