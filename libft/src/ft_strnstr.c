/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:27:42 by ainthana          #+#    #+#             */
/*   Updated: 2024/11/21 20:25:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*found;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *) big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			while (big[i + j] == little[j] && little[j] && i + j < len)
				j++;
			if (little[j] == '\0')
			{
				found = (char *) &big[i];
				return (found);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;

// 	str1 = "abcdefghijk";
// 	str2 = "ijkl";
// 	printf("%s", ft_strnstr(str1, str2, 15));
// }