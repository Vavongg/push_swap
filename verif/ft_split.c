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

t_node  *ft_splitlst(char *str)
{
    t_node  *head;
    t_node  *current;
    t_node  *new_node;
    size_t  start;
    size_t  end;
    char    *word;

    head = NULL;
    current = NULL;
    start = 0;
    end = 0;
    if (!str)
        return (NULL);
    while (str[start])
    {
        while (str[start] == ' ' && str[start])
            start++;
        if (!str[start])
            break ;
        end = start;
        while (str[end] && str[end] != ' ')
            end++;
        word = subcopy(str + start, end - start);
        if (!word)
            return (NULL);
        new_node = ft_lstnew(ft_atol(word));
        if (!new_node)
            return (NULL);
        if (!head)
            head = new_node;
        else
            current->next = new_node;
        current = new_node;
        start = end;
    }
    return (head);
}
