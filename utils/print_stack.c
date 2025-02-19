/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:27:39 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/14 14:43:28 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack, char name)
{
    t_node *current;
	
	/*if (!stack || !stack->head)
	{
		ft_printf("%s is empty.\n", name);
		return ;
	}*/
	current = stack->head;
    ft_printf("Stack %c: ", name);
    while (current)
    {
        ft_printf("%d -> ", current->value);
        current = current->next;
    }
    ft_printf("NULL\n");
}
