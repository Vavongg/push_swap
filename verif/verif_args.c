/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:18 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/07 17:22:53 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long convert_args(char *str)
{
    long num;

    if (!ft_is_num(str))
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

int ft_is_num(char *str)
{
    int i = 0;

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

void	verif_args(char **argv)
{
    int		i;
	int		j;
    long	num;
	char 	**split_args;

    i = 1;
    split_args = ft_split(argv[i], ' ');
    while (argv[i])
    {
        if (!split_args)
        {
            print_error();
            exit(EXIT_FAILURE);
        }
        j = 0;
        while (split_args[j])
        {
            num = convert_args(split_args[j]);
            j++;
        }
        free_args(split_args);
        i++;
    }
}

