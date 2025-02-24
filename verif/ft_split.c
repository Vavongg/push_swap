/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:18 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/24 15:14:24 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	ft_count(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			j++;
			while (str[i] != c && str[i])
				i++;
			if (str[i] == '\0')
				return (j);
		}
		i++;
	}
	return (j);
}

char	*ft_putword(char const *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	word = malloc(sizeof (char) * (end - start) + 1);
	if (!word)
		return (NULL);
	while (start + i < end)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	i = ((j = ((k = 0))));
	split = malloc(sizeof (char *) * (ft_count(s, c) + 1));
	if (!split)
		return (NULL);
	while (i < ft_count(s, c) && s[j])
	{
		while (s[j] == c && s[j])
			j++;
		k = j;
		while (s[k] != c && s[k])
			k++;
		split[i] = ft_putword(s, j, k);
		j = k;
		if (!split[i])
			return (ft_free_tab(split), NULL);
		i++;
	}
	split[i] = NULL;
	return (split);
}
