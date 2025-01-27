/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:08:05 by ainthana          #+#    #+#             */
/*   Updated: 2024/11/21 19:50:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*ft_putword(char const *s, size_t start, size_t end)
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

static char	**ft_free_tab(char **tab)
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
