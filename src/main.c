/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:39:20 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/28 02:20:36 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
		exit(EXIT_FAILURE);
    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
    {
        free(stack_a);
        free(stack_b);
        return (1);
    }
    stack_a->head = NULL;
    stack_b->head = NULL;
    stack_a->size = 0;
    stack_b->size = 0;
   	verif_args(stack_a, stack_b, argv, argc);
    index_stack(stack_a);
    print_stack(stack_a, 'a');
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
