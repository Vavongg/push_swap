/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:40:03 by ainthana          #+#    #+#             */
/*   Updated: 2025/03/17 14:27:44 by ainthana         ###   ########.fr       */
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
# include <limits.h>

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

//algorithmes
int		is_sorted(t_stack *stack);

//move_stack
void	ft_push(t_stack *src, t_stack *dst, char c);
void	ft_reverse_rotate(t_stack *lst, char c);
void	ft_reverse_rotate_both(t_stack *a, t_stack *b);
void	ft_rotate(t_stack *lst, char c);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	ft_swap(t_stack *lst, char c);
void	swap_both(t_stack *stack_a, t_stack *stack_b);

//utils
void	print_stack(t_stack *stack, char name);
void	print_error(void);
void	free_stack(t_stack *stack);
t_node	*ft_lstnew(int value);
int		create_node(t_stack *stack, char *str);
void	add_node(t_stack *stack, t_node *new_node);
void	index_stack(t_stack *stack);

//verif
long	ft_atol(char *nb);
int		ft_isdigit(int c);
int		ft_is_duplicate(t_stack *stack, int value);
long	convert_args(char *str);
void	free_args(char **args);
char	**ft_split(char *str, char sep);
int		ft_is_num(char *str);
void	verif_args2(char **argv, t_stack *stack_a, t_stack *stack_b);
void	verif_args1(char *arg, t_stack *stack_a, t_stack *stack_b);
void	handle_error(t_stack *stack_a, t_stack *stack_b, char **split_args);

#endif
