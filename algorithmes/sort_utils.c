/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:27:09 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/20 00:12:33 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return (1);
	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_min(t_stack *a)
{
	t_node	*current;
	int		min;

	if (!a || !a->head)
		exit(EXIT_FAILURE);
	current = a->head;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	count_r(t_stack *stack, int index)
{
	int		counter;
	t_node	*current;

	if (!stack || !stack->head)
		return (0);
	counter = 0;
	current = stack->head;
	while (current && current->index != index)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}
