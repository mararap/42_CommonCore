/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:48:34 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/25 18:08:23 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int	i = 0;

	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(void *p_content)       // ft_new_node
{
	t_list *p_node;
	p_node = malloc(sizeof(t_list));
	if(p_node == NULL)
		return (NULL);
	p_node->data = p_content;     // -> is kurz für (*p_node).data
	p_node->next = NULL;
	return (p_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		t_list *tmp = *lst;
		while (tmp->node)
			tmp = tmp->node;
		tmp->node = new;
	}
}

#include <stdio.h>

int	main()
{
	t_list	*head = NULL;
	t_list	*new;
	int		*num;
	int		size;
	
	int	i = 24;
	while (i <= 42)
	{
		num = malloc(sizeof(int));
		*num = i;
		new = ft_lstnew(num);
		ft_lstadd_back(&head, new);
		i++;
	}
	size = ft_list_size(head) - 1;
	printf("size = %d\n", size);
}
