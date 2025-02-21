/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:18 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/17 16:45:20 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_putword(char *str, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	word = malloc(sizeof (char) * (end - start) + 1);
	if (!word)
		return (NULL);
	while (start + i < end)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	create_and_add_node(t_stack *stack, char *str, size_t start, size_t end)
{
	int		value;
	t_node	*new_node;
	char	*word;

	word = ft_putword(str, start, end);
	if (!word)
		return (0);
	value = ft_atoi(word);
	free(word);
	new_node = ft_lstnew(value);
	if (!new_node)
		return (0);
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size++;
	return (1);
}

void	ft_split(t_stack *stack, char *str, char c)
{
	size_t	i;
	size_t	j;

	if (!stack || !str)
		return ;
	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] == c && str[j])
			j++;
		i = j;
		while (str[i] != c && str[i])
			i++;
		if (i > j)
		{
			if (!create_and_add_node(stack, str, j, i))
				return ;
		}
		j = i;
	}
}
