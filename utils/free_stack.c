/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:57:31 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/27 19:39:51 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return ;

	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
		temp = NULL;
	}
	free(stack);
	stack = NULL;
}