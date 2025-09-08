/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:37:42 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/08 13:29:10 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // Program for Implementation of a Singly Linked List

#include <stdlib.h>

// define Node structure
typedef struct	s_Node
{
	// Data field. Can add more data according to our need.
	int				*num;
	// Pointer to next node
	struct s_Node	*next;
}					t_Node;
/*
// function to create a new node and return pointer to it
t_Node *ft_lstnew(int *num)
{
	t_Node *newNode = (t_Node *)malloc(sizeof(t_Node));
	newNode->*num = *num;

	// initially assigning the next pointer to NULL
	newNode->next = NULL;

	return newNode;
}*/

void	ft_Array_Linked_List (int arr[], int count)
{
	t_Node *last;
	t_Node *prev;
	first = (struct s_Node *)malloc(sizeof(struct s_Node));
	first->num = arr[0];
	first->next = NULL;
	prev = first;
	int	i;
	
	i = 1;
	while(i < count)
	{
		last = (struct s_Node *)malloc(sizeof(struct s_Node));
		last->num = arr[i];
		last->next = NULL;
		prev->next = last;
		prev = last;
		i++;
	}
}

/*
int	main()

	//creating, initializing and linking
	t_Node *head = ft_lstnew(stack[i]);

	// create head -> next -> NULL
	head->next = ft_lstnew(stack[i + 1]);

	// create head -> next -> next -> NULL
	head->next->next = ft_lstnew(stack[i + 2]);
	
	printf("Linked List: ");
	t_Node *temp = first;
	while (temp)
	{
		printf("%d ", temp->*num);
		temp = temp->next;
	}
	return (0);
}*/


