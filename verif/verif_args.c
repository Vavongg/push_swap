/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:08:29 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/25 02:07:41 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**verif_args(int argc, char **argv)
{
    char    **args;
    int     i;
    
    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        i = 0;
    }
    else
    {
        args = argv;
        i = 1;
    }
    while (args && args[i])
    {
        check_number(args[i], args, i);
        i++;
    }
	return (args);
}
