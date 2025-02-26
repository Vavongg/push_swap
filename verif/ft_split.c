/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:18 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/24 15:14:24 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char    *subcopy(char *str, size_t len)
{
    char    *sub;
    size_t    i;

    i = 0;
    sub = malloc(sizeof(char) * (len + 1));
    if (!sub)
        return (NULL);
    while (i < len)
    {
        sub[i] = str[i];
        i ++;
    }
    sub[i] = '\0';
    return (sub);
}

long int    transcheck(char *str)
{
    char        *temp;
    long int    num;
    size_t        j;

    j = 0;
    while (str[j] && str[j] != ' ')
        j ++;
    temp = subcopy(str, j);
    if (!temp || !checkdigit(temp))
    {
        if (temp)
            free(temp);
        return (CHECK_ERROR);
    }
    else
    {
        num = ft_atoi(temp);
        free(temp);
        str = str + j;
    }
    return (num);
}

t_list    **splitlst(char *str, t_node **lst)
{
    long int    num;
    size_t        i;

    i = 0;
    while (str && str[i] == ' ')
        i ++;
    while (str && str[i])
    {
        num = transcheck(str + i);
        if (num < -2147483648 || num > 2147483647 || lstcheck(num, lst))
        {
            lstfree(lst);
            return (NULL);
        }
        else
        {
            lstadd(lstnew(num), lst);
            while (str[i] && str[i] != ' ')
                i ++;
            while (str[i] == ' ')
                i ++;
        }
    }
    return (lst);
}
