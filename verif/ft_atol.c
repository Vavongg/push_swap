/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:14 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/27 16:02:52 by ainthana         ###   ########.fr       */
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
		if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && nb[i] - '0' > LONG_MAX % 10))
			return (sign == 1 ? LONG_MAX : LONG_MIN);
		result = result * 10 + (nb[i] - '0');
		i++;
	}
	return (result * sign);
}