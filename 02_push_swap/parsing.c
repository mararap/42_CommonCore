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
typedef struct	s_num
{
	void			*value;
	struct s_num	*next;
	struct s_num	*prev;
}			t_num;

int main(int ac, char **av)
{
	t_num	*head;

	head = malloc(sizeof(t_num))
	if(head == NULL)
		exit(2);
	head->value=ft_atoi(av + 1);
	head->next = NULL;
	head->prev = NULL;


	Node *curr = root;
	while (curr != NULL
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
