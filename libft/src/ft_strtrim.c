/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:07:34 by ainthana          #+#    #+#             */
/*   Updated: 2024/11/19 13:47:46 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (check_set(s1[i], set) == 1)
	{
		i++;
	}
	while (check_set(s1[j], set) == 1)
	{
		j--;
	}
	str = ft_substr(s1, i, (j - i + 1));
	return (str);
}

// int	main(void)
// {
// 	char	*s;
// 	char	*t;
//
// 	s = "lorem ipsum dolor sit amet";
// 	t = "te";
// 	printf("%s\n", ft_strtrim(s, t));
// }