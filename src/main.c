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

int	main(int argc, char **argv)
{
    t_stack	*stack_a;
    t_stack	*stack_b;

    if (argc < 2) 
    {
        ft_printf("%s\n", "Error : Minimum 1 arg");
        return (1);
    }

    // Initialisation des stacks
    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
        return (1);

    stack_a->head = NULL;
    stack_b->head = NULL;
    stack_a->size = 0;
    stack_b->size = 0;

    ft_split(stack_a, argv[1], ' ');

    ft_printf("Avant toute opération :\n");
    print_stack(stack_a, 'a');
    print_stack(stack_b, 'b');

    ft_push(stack_a, stack_b, 'b');
    ft_printf("\nAprès push (pb) :\n");
    print_stack(stack_a, 'a');
    print_stack(stack_b, 'b');

    ft_swap(stack_a, 'a');
    ft_printf("\nAprès swap (sa) :\n");
    print_stack(stack_a, 'a');
    print_stack(stack_b, 'b');

    ft_rotate(stack_a, 'a');
    ft_printf("\nAprès rotate (ra) :\n");
    print_stack(stack_a, 'a');
    print_stack(stack_b, 'b');

    ft_reverse_rotate(stack_a, 'a');
    ft_printf("\nAprès reverse rotate (rra) :\n");
    print_stack(stack_a, 'a');
    print_stack(stack_b, 'b');
	
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}