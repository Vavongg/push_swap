/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:21:00 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/27 18:21:00 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*splitlst(char *str, t_stack *stack)
{
    long int	num;
    size_t		i;
    t_node		*head = NULL;
    t_node		*current = NULL;
    t_node		*new_node;

    i = 0;
    while (str && str[i] == ' ')
        i++;
    while (str && str[i])
    {
        num = parse_args(str + i);
		if (num == LONG_MIN || ft_is_duplicate(stack, (int)num))
		{
            free_stack(stack);
            return (NULL);
        }
        new_node = ft_lstnew((int)num);
        if (!new_node)
            return (NULL);
        if (!head)
            head = new_node;
        else
            current->next = new_node;
        current = new_node;
        stack->size++;

        while (str[i] && str[i] != ' ')
            i++;
        while (str[i] == ' ')
            i++;
    }
    return (head);
}
