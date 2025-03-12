/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:27:39 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/10 14:27:20 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack, char name)
{
	t_node	*current;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	ft_printf("Stack %c : \n", name);
	while (current)
	{
		ft_printf("[%d], [Index: %d]\n", current->value, current->index);
		current = current->next;
	}
}

void	print_error(void)
{
	ft_printf("Error\n");
}
