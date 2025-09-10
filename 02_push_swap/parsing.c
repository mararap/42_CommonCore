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

#include "push_swap.h"

// ac, **av reads all numbers as characters/character strings



// linked list //

t_stack	*ft_parsing(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;

	if(ac < 2) //ft_print_error
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	else if(ac == 2) //ft_parse_quoted;
		stack_a = ft_parse_quoted(av);
	else
		ft_parse_args(av, &stack_a) //ft_parse_args;
	return (stack_a);
}

t_stack	*ft_parse_quoted(char **av)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;
	int		j;

	stack_a = NULL;
	i = 0;
	tmp = ft_split(av[1], 32);
	ft_parse_args(tmp, &stack_a);
	ft_freestr(tmp);
	ft_free(tmp);
	return (stack_a);
}

void	ft_parse_args(char **av, t_stack **stack_a)
{
	long	i;

	i = 1;
	while(av[i])
	{
		ft_add_last(stack_a, ft_new_node(ft_atoi(argv[i])));
		i++;
	}
}

t_stack	*ft_new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_print_error();
	new->nbr = value;
	new->next = NULL;
	return (new);
}

void	ft_add_last(t_stack **stack, t_stack *new_node)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new_node;
	else
		(ft_last_node(*stack))->next = new_node;
}

t_stack	*ft_last_node(t_stack *end)
{
	if (!end)
		return (NULL);
	while (end->next)
		end = end->next;
	return(end);
}

int	main(int ac, char **av)
{
	ft_parsing(ac, av);
	return (0);
}
// array //
/*
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
*/
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
}*/
