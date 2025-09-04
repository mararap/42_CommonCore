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

// ac, **av reads all numbers as characters/character strings



// linked list //

//create struct for stacks
/*typedef struct	s_node
{
	int				value;
	struct s_node	*next;
}			t_node;

int main(int ac, char **av)
{
	t_node	*root;

	root = malloc(sizeof(t_node));
	if(root == NULL)
		exit(2);
	root->x = 15;
	root->next = NULL;

	insert_end(&root, -2);
	insert_end(&root, 11);

	Node *curr = root;
	while (curr != NULL
	{
		curr = curr->next;
	}
	return (0);
}
*/
// array //
int ft_atoi(const char *str);


#include <stdio.h>
int	main(int ac, char **av)
{

	int		stack_a[ac - 1];
	int		i;

	i = 0;
	while (i < ac-1)
	{
		stack_a[i] = ft_atoi(av[i+1]);
		i++;
	}
	i = 0;
	while (i < ac-1)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
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
