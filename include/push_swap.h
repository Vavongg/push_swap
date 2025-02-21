/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:40:03 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/21 14:48:27 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*head;
}	t_stack;

void	ft_push(t_stack *src, t_stack *dst, char c);
void	ft_reverse_rotate(t_stack *lst, char c);
void	ft_rotate(t_stack *lst, char c);
void	ft_swap(t_stack *lst, char c);


void	print_stack(t_stack *stack, char name);
void	free_stack(t_stack *stack);
t_node	*ft_lstnew(int value);

int		ft_isdigit(int c);
long	ft_atoi(char *nb);
void	ft_split(t_stack *stack, char *str, char c);
int		create_and_add_node(t_stack *stack, char *str, size_t start, size_t end);




#endif
