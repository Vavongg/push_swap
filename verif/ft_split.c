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

t_node *splitlst(char *str, t_stack *stack)
{
    long	num;
    size_t	i;
    t_node *head;
    t_node *current;
    t_node *new_node;
    char **args;

    i = 0;
    head = NULL;
    current = NULL;
    args = ft_split(str, ' ');
	if (!args)
		return NULL;
    while (args[i])
    {
        num = ft_atol(args[i]);
        if (ft_is_duplicate(stack, (int)num))
        {
            free_args(args);
            free_stack(stack);
            return NULL;
        }
        new_node = ft_lstnew((int)num);
        if (!new_node)
        {
            free_args(args);
            return NULL;
        }
        if (!head)
            head = new_node;
        else
            current->next = new_node;
        current = new_node;
        i++;
    }
    free_args(args);
	return (head);
}

static int	count_words(char *str, char sep)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
			count++;
		while (*str && *str != sep)
			str++;
	}
	return (count);
}

static char	*extract_word(char *str, char sep)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char sep)
{
	int		words;
	char	**tab;
	int		i;

	i = 0;
	words = count_words(str, sep);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
		{
			tab[i] = extract_word(str, sep);
			if (!tab[i])
			{
				free_args(tab);
				return (NULL);
			}
			i++;
			while (*str && *str != sep)
				str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

void	free_args(char **args)
{
	int	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}
