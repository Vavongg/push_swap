/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:39:20 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/25 02:05:07 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;
    int num;

    if (argc < 2)
        return (1);

    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
        return (1);
    stack_a->head = NULL;
    stack_b->head = NULL;
    stack_a->size = 0;
    stack_b->size = 0;

    if (argc == 2)
        i = 0;
    else
        i = 1;
    while (argv[i])
    {
        num = ft_atol(argv[i]);
        if (ft_is_duplicate(num, &argv[i], i))
        {
            free_stack(stack_a);
            ft_printf("Error\n");
            return (1);
        }
        else if (!create_node(stack_a, argv[i], 0, ft_strlen(argv[i])))
        {
            free_stack(stack_a);
            ft_printf("Error\n");
            return (1);
        }
        i++;
    }
	print_stack(stack_a, 'a');
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
