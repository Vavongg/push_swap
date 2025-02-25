/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:08:29 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/25 01:03:57 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    free_args(char **args, int is_split)
{
    int i = 0;
    if (is_split)
    {
        while (args[i])
        {
            free(args[i]);
            i++;
        }
        free(args);
    }
}

void    check_number(char *arg, char **args, int i, int is_split)
{
    long num;
    if (!is_valid_number(arg) || (num = ft_atol(arg)) < INT_MIN 
								|| num > INT_MAX || ft_is_duplicate(num, args, i))
    {
        ft_printf("Error\n");
        free_args(args, is_split);
    }
}

void    verif_args(int argc, char **argv)
{
    char    **args;
    int     i;
    int     is_split;
    
    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        i = 0;
        is_split = 1;
    }
    else
    {
        args = argv;
        i = 1;
        is_split = 0;
    }
    
    while (args[i])
    {
        check_number(args[i], args, i, is_split);
        i++;
    }
    
    if (is_split)
        free_args(args, 1);
}

