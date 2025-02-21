/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:32:44 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/21 12:35:57 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ../include/push_swap.h

int	ft_is_duplicate(int nb, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}
