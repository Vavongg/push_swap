/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:18 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/27 19:23:19 by ainthana         ###   ########.fr       */
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

long int check_word(char *str)
{
    char        *temp;
    long int    num;
    size_t      j;

    j = 0;
    if (!str || *str == '\0')
    {
        print_error();
        return (0);
    }
    while (str[j] == ' ')
        j++;
    while (str[j] && str[j] != ' ')
        j++;
    temp = subcopy(str, j);
    if (!temp || !is_valid_number(temp))
    {
        free(temp);
        print_error();
        return (0);
    }
    num = ft_atol(temp);
    if (num < INT_MIN || num > INT_MAX)
    {
        free(temp);
        print_error();
        return (0);
    }
    free(temp);
    return (num);
}
