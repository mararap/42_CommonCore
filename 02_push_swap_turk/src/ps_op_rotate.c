/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:09:27 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/28 21:34:02 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_rotate(t_node **stack)
{
	t_node	*last;
	ssize_t	len;

	len = ps_stacklen(*stack);
	if (!stack || !*stack || len == 1)
		return ;
	last = ps_find_tail(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ps_ra(t_node **a)
{
	ps_rotate(a);
	write (1, "ra\n", 3);
}

void	ps_rb(t_node **b)
{
	ps_rotate(b);
	write (1, "rb\n", 3);
}

void	ps_rr(t_node **a, t_node **b)
{
	ps_rotate(a);
	ps_rotate(b);
	write (1, "rr\n", 3);
}
