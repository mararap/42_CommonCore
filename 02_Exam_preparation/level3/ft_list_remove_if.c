/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 23:42:44 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/30 00:21:10 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;

	if ((begin_list == NULL || (*begin_list) == NULL))
		return ;
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list; // save content of current node (derefereced pointer?)
		*begin_list = (*begin_list)->next; // move pointer to next node
		free(tmp); // free what was pointer to begin_list before
		ft_list_remove_if(begin_list, data_ref, cmp); // call funcion recursiveley
	}
	else
		ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
}
