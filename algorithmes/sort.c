/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:27:07 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/17 14:26:20 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *a)
{
	int		biggest_value;
	t_node	*current;

	current = a->head;
	biggest_value = get_max(a);
	if (!a || !a->head || !a->head->next || !a->head->next->next)
		return ;
	if (current->value == biggest_value)
	{
		ft_rotate(a, 'a');
		if (a->head->value > a->head->next->value)
			ft_swap(a, 'a');
	}
	else if (current->next->value == biggest_value)
	{
		ft_reverse_rotate(a, 'a');
		if (a->head->value > a->head->next->value)
			ft_swap(a, 'a');
	}
	else
	{
		if (a->head->value > a->head->next->value)
			ft_swap(a, 'a');
	}
}
