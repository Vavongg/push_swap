/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:27:09 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/23 11:41:37 by ainthana         ###   ########.fr       */
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

int	get_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_index;

	current = stack->head;
	min_index = current->index;
	while (current->next)
	{
		current = current->next;
		if (current->index < min_index)
			min_index = current->index;
	}
	return (min_index);
}

int	count_r(t_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
	else if (length == 2)
		ft_swap(stack_a, 'a');
	else if (length == 3)
		simple_sort(stack_a, length);
	else if (length <= 7)
		insertion_sort(stack_a, stack_b, length);
	else if (length > 7)
	{
		k_sort1(stack_a, stack_b, length);
		k_sort2(stack_a, stack_b, length);
	}
	else
		print_error();
}
