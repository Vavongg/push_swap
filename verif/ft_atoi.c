/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:14 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/21 16:28:40 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atoi(char *nb)
{
	long			i;
	int				sign;
	long			result;

	i = 0;
	sign = 1;
	result = 0;
	while (nb[i] == 32 || (nb[i] >= 9 && nb[i] <= 13))
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nb[i]))
	{
		result *= 10;
		result += nb[i] - '0';
		i++;
	}
	return (result * sign);
}

