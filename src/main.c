/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:39:20 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/10 14:13:11 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void init_stacks(t_stack **stack_a, t_stack **stack_b)
{
    *stack_a = malloc(sizeof(t_stack));
    *stack_b = malloc(sizeof(t_stack));
    if (!*stack_a || !*stack_b)
    {
        free(*stack_a);
        free(*stack_b);
        exit(EXIT_FAILURE);
    }
    (*stack_a)->head = NULL;
    (*stack_b)->head = NULL;
    (*stack_a)->size = 0;
    (*stack_b)->size = 0;
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
    {
        print_error();
        return (1);
    }
    init_stacks(&stack_a, &stack_b);
    verif_args(argv, stack_a, stack_b);
	index_stack(stack_a);
    print_stack(stack_a, 'a');

    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}