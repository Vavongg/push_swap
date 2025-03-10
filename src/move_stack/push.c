/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:49:43 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/10 19:06:25 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_push(t_stack *src, t_stack *dst, char c)
{
	t_node	*temp;

	if (!src || !src->head)
		return ;
	temp = src->head;
	src->head = src->head->next;
	temp->next = dst->head;
	dst->head = temp;
	dst->size++;
	src->size--;
	ft_printf("p%c\n", c);
}
