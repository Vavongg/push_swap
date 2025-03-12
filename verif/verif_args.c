/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:18 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/10 14:25:12 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	convert_args(char *str)
{
	long	num;

	if (!ft_is_num(str))
		return (2147483648);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (2147483648);
	return (num);
}

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	verif_args(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	long	num;
	char	**split_args;

	i = 1;
	while (argv[i])
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
		{
			free_stack(stack_a);
			free_stack(stack_b);
			print_error();
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (split_args[j])
		{
			num = convert_args(split_args[j]);
			if (ft_is_duplicate(stack_a, num) || num == 2147483648)
			{
				free_stack(stack_a);
				free_stack(stack_b);
				free_args(split_args);
				print_error();
				exit(EXIT_FAILURE);
			}
			if (!create_node(stack_a, split_args[j]))
			{
				free_stack(stack_a);
				free_stack(stack_b);
				free_args(split_args);
				print_error();
				exit(EXIT_FAILURE);
			}
			j++;
		}
		free_args(split_args);
		i++;
	}
}
