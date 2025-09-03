/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:06:31 by marapovi          #+#    #+#             */
/*   Updated: 2025/08/11 19:06:34 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include
// 
// stack a as linked list

typedef struct	s_node
{
	int				nb;
	struct s_node	*next;
}			t_node;

int main(int ac, char **av)
{
	t_node	*root;

	root = malloc(sizeof(t_node));
	root->next = malloc(sizeof(t_node));
	root->next->next = malloc(sizeof(t_node));

	root->n = 42;
	root->next->n = 1337;
	root->next->next->n = 21;
	root->next->next->next = NULL;
	// "i" for array
	// "*current" for linked list
	t_node	*current;

	current = root;
	while (current != NULL)
	{
		current = current->next;
	}
/*
	root = malloc(sizeof(t_node));
	node_1 = malloc(sizeof(t_node));
	node_2 = malloc(sizeof(t_node));
	
	root->nb = 42;
	node_1->nb = 1337;
	node_2->nb = 21;

	root->next = node 1;
	root->next->next = node_2;
	root->next->next->next = NULL;
}*/



//
// input check, error handling
// 
// initalize variables
//
// find out how many numbers there are in the list = len_a
// allocate memory
//
// pb pb
// length of stack_b = 2
// loop:
//	i = 0;
//	j = 0;
//	check first integer stack_a[i]
//		how many operations to move to top with ra?
//			if i * 2 < len_a
//		how many operations to move to top with rra?
//			save
//		loop: find next smallest number in stack_b
//			if stack_b[j] > stack_a[i]
//				j++;
//		if j * 2 < len_b
//			rb_moves = j
//		else if j * 2 >= len_b
//			rrb_moves = len_b - j
//
//		how many operations to move stack_b[i] to top with rb?
//		how many operations to move stack_b[i] to top with rrb?
//
//

int	main(argc, **argv){

// input-checks;
// error handling;
//
// malloc for (argc + 1) * sizeof_int;
	// null-check;
// itol;
// 




}
