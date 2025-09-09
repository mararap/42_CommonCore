/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:01:03 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/04 13:55:22 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// ac, **av reads all numbers as characters/character strings



// linked list //

t_stack *ft_parse(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;

	stack_a = malloc(sizeof(t_stack));
		if(stack_a[0] == NULL)
			return (1);
	if(ac < 2)
		//ft_errorhandling;
	elseif(ac == 2)
		//ft_parse_quote;
	else
		//ft_parse_args;

	head->value=ft_atoi(av + 1);
	head->next = NULL;
	head->prev = NULL;


	s_num *curr = root;
	while (curr != NULL)
	{
		curr = curr->next;
	}
	return (0);
}

// array //

int	main(int ac, char **av)
{

	int		stack_a[ac - 1];
	int		i;
	int		size;

	size = ac - 1;
	i = 0;
	while (i < size)
	{
		stack_a[i] = ft_atoi(av[i+1]);
		i++;
	}
	ft_rrotate(size, stack_a);
	i = 0;
	while (i < size)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	return (0);
/*
	int		*stack_b;
	int		index_a;
	int		index_b;
	
	stack_a = malloc(ac * sizeof(int));
	stack_b = malloc(ac * sizeof(int));
	index_a = 0;
	index_b = 0;

	while ()
	{

	}
*/


}
