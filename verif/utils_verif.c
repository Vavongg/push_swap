/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:32:25 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/27 15:43:03 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_duplicate(int nb, char **argv, int i)
{
	long	value;

	i++;
	while (argv[i])
	{
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		if ((int)value == nb)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_valid_number(char *str)
{
    size_t	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!str[i + 1] || !ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_putword(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	i = 0;
	if (!s || start >= end)
		return (NULL);
	word = malloc(sizeof(char) * (end - start + 1));
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
