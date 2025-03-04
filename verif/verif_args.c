/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:18 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/28 02:28:57 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

long parse_args(char *str)
{
    long	num;

    if (!is_valid_number(str))
    {
        print_error();
        exit(EXIT_FAILURE);
    }
    num = ft_atol(str);
    if (num < INT_MIN || num > INT_MAX)
    {
        print_error();
        exit(EXIT_FAILURE);
    }
    return (num);
}

void	verif_args(t_stack *stack_a, t_stack *stack_b, char **argv, int argc)
{
	int	num;
	int	i;

	if (argc == 2)
    {
		i = 0;
		stack_a->head = splitlst(argv[1], stack_a);
	}
    else
        i = 1;
    while (argv[i])
    {
        num = ft_atol(argv[i]);
        if (num < INT_MIN || num > INT_MAX || ft_is_duplicate(stack_a, num))
        {
            free_stack(stack_a);
            free_stack(stack_b);
            print_error();
            exit(EXIT_FAILURE);
		}
        else if (!create_node(stack_a, argv[i]))
        {
            free_stack(stack_a);
            free_stack(stack_b);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}
