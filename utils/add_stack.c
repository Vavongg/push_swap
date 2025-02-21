/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_add_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:02:16 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/21 17:40:56 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_node(t_stack *stack, t_node *new_node)
{
	t_node	*current;

	if (!stack->head)
		stack->head = new_node;
	else
	{
		current = stack->head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

int	create_node(t_stack *stack, char *str, size_t start, size_t end)
{
	int		value;
	t_node	*new_node;
	char	*word;

	word = ft_putword(str, start, end);
	if (!is_valid_number(word))
	{
		free(word);
		return (0);
	}
	value = ft_atol(word);
	free(word);

	new_node = ft_lstnew(value);
	if (!new_node)
		return (0);

	add_node(stack, new_node);
	return (1);
}
