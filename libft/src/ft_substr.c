/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:05:20 by ainthana          #+#    #+#             */
/*   Updated: 2024/11/19 16:47:20 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_max(long x, long y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

static unsigned long	ft_min(long x, long y)
{
	if (x <= 0 || y <= 0)
		return (0);
	if (x < y)
		return (x);
	else
		return (y);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	k;

	i = 0;
	if (!s)
		return (NULL);
	k = ft_max((ft_strlen(s) - start), 0);
	if (len > k)
		len = k;
	str = malloc(sizeof(char) * (ft_min(k, len) + 1));
	if (!str)
		return (NULL);
	while (i < ft_min(k, len))
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
