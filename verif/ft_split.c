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
	int	i;
	
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}
