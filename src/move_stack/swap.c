/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:51:32 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/10 19:06:34 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_swap(t_stack *lst, char c)
{
	t_node	*first;
	t_node	*second;

	if (!lst || !lst->head || !lst->head->next)
		return ;
	first = lst->head;
	second = lst->head->next;
	first->next = second->next;
	second->next = first;
	lst->head = second;
	ft_printf("s%c\n", c);
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, 'a');
	ft_swap(stack_b, 'b');
	ft_printf("ss\n");
}
