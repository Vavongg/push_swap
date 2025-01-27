/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:09:06 by ainthana          #+#    #+#             */
/*   Updated: 2024/11/18 15:58:16 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = 0;
	dst = malloc(sizeof(*s) * (ft_strlen(s)+ 1));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = f(i, *(s + i));
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
