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

char *subcopy(char *str, size_t len)
{
    char *sub;
    size_t i;

    i = 0;
    if (!str)
        return (NULL);
    sub = malloc(sizeof(char) * (len + 1));
    if (!sub)
        return (NULL);
    while (i < len)
    {
        sub[i] = str[i];
        i++;
    }
    sub[i] = '\0';
    return (sub); 
}

int check_args(char *str)
{
    size_t i;

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
    long num;

    if (!check_args(str))
    {
        print_error();
        return (LONG_MIN);
    }
    num = ft_atol(str);
    if (num <= LONG_MIN || num < INT_MIN || num > INT_MAX)
    {
        print_error();
        return (LONG_MIN);
    }
    return (num);
}
