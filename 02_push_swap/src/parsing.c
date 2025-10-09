/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:01:03 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/09 17:48:52 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ac, **av reads all numbers as characters/character strings
/*
long int	atol(char *str);
{
	long int num;
*/
	


// linked list //

t_node	*ft_parsing(int ac, char **av)
{
	t_node	*stack_a;

	stack_a = NULL;
	if(ac < 2)
		ft_print_error(); //ft_print_error
//	else if(ac == 2) //ft_parse_quoted;
//		stack_a = ft_parse_quoted(av);
	else
		ft_parse_args(av, &stack_a, 1); //ft_parse_args;
	return (stack_a);
}

t_node	*ft_parse_quoted(char **av)
{
	t_node	*stack_a;
	char	**tmp;
	
	stack_a = NULL;
	tmp = ft_split(av[1], 32);
	ft_parse_args(tmp, &stack_a, 0);
	ft_free_str_arr(tmp);
	return (stack_a);
}

void	ft_parse_args(char **av, t_node **stack_a, size_t	i)
{
	while(av[i])
	{
		ft_add_last(stack_a, ft_new_node(ft_atol(av[i])));
		i++;
	}
}

t_node	*ft_new_node(long nbr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_print_error();
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

void	ft_add_last(t_node **stack, t_node *new_node)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new_node;
	else
		(ft_last_node(*stack))->next = new_node;
}

t_node	*ft_last_node(t_node *end)
{
	if (!end)
		return (NULL);
	while (end->next)
		end = end->next;
	return(end);
}

void	ft_print_error()
	{
		write (2, "Error\n", 6);
		exit (1);
	}

int	nodes_counter(t_node *current)
{
	int count;

	count = 0;
	while(current)
	{
		++count;
		current = current->next;
	}
	return (count);
}

void	ft_free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_free_str_arr(char **str_arr)
{
	size_t	i;
	
	i = 0;
	while(str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	str_arr = NULL;
}

// ft_free
// ft_freestr

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
