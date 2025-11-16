/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:23:10 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/16 19:35:41 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_swap(t_node **head)
{
	ssize_t	len;

	len = ps_stacklen(*head);
	if (!*head || !head || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	ps_sa(t_node **a)
{
	ps_swap(a);
	write (1, "sa\n", 3);
}

void	ps_sb(t_node **b)
{
	ps_swap(b);
	write (1, "sb\n", 3);
}

void	ps_ss(t_node **a, t_node **b)
{
	ps_swap(a);
	ps_swap(b);
	write (1, "ss\n", 3);
}
