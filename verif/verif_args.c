/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:08:29 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/24 16:43:12 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	verif_args(int argc, char **argv)
{
	int		i;
	char 	**args;

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
}
