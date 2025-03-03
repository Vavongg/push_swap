/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:32:25 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/27 17:22:07 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(char *nb)
{
	long	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nb[i] == 32 || (nb[i] >= 9 && nb[i] <= 13))
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			sign = -1;
		i++;
	}
	while (nb[i] && ft_isdigit(nb[i]))
	{
		result = result * 10 + (nb[i] - '0');
		i++;
	}
	return (result * sign);
}

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
