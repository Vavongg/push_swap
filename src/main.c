/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:39:20 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/14 14:59:40 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*new_node;
	int		i;

	// Vérification du nombre d'arguments
	if (argc < 3) // Besoin d'au moins 2 nombres pour tester toutes les opérations
	{
		ft_printf("%s\n", "Error : Minimum 2 args");
		return (1);
	}

	// Initialisation des stacks
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);

	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->size = 0;
	stack_b->size = 0;

	// Remplir stack_a avec les arguments
	i = 1;
	while (i < argc)
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		if (!new_node)
			return (1);
		new_node->next = stack_a->head;
		stack_a->head = new_node;
		stack_a->size++;
		i++;
	}

	// Afficher avant toute opération
	ft_printf("Avant toute opération :\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	// Exécuter push : déplace le premier élément de a vers b
	ft_push(stack_a, stack_b, 'b');
	ft_printf("\nAprès push (pb) :\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	// Exécuter swap sur stack_a
	ft_swap(stack_a, 'a');
	ft_printf("\nAprès swap (sa) :\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	// Exécuter rotate sur stack_a
	ft_rotate(stack_a, 'a');
	ft_printf("\nAprès rotate (ra) :\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	// Exécuter reverse rotate sur stack_a
	ft_reverse_rotate(stack_a, 'a');
	ft_printf("\nAprès reverse rotate (rra) :\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	// Libération mémoire
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
