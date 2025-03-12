/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:21:11 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/27 16:21:11 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	index_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	while (current)
	{
		index = 0;
		compare = stack->head;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
