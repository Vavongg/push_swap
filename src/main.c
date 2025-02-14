/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:39:20 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/14 14:59:40 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main (int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*node;
	
	(void)argv;
	if (argc < 2)
		return (0);

	stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));

	if (!stack_a || !stack_b)
		return (1);

	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->size = 0;
	stack_b->size = 0;

	node = malloc(sizeof(t_node));
    if (!node)
        return (1);
    node->value = 42;
    node->next = NULL;
    stack_a->head = node;

	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
