/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 23:30:00 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/29 23:41:46 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	struct s_list	*next; // used exclusiveley for linked lists; pointer to next node
	void			*data; // pointer to content
}					t_list; // is used like data types (int i, t_list *previous...)

#include "stddef.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL) // check if pointer to list exists
	{
		if (begin_list->data != NULL) // check if content of pointer to list is not NULL
			(*f)(begin_list->data); // apply function-pointer to first node (content)
		begin_list = begin_list->next; // move pointer to next node
	} // loop until it reaches NULL 
}
