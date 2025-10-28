/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:28:58 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/28 21:34:10 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ps_rr_until(t_node **a, t_node **b, t_node *stop)
{
	while (*a != stop->target && *b != stop)
		ps_rr(a, b);
	ps_set_curr(*a);
	ps_set_curr(*b);
}

static void	ps_rrr_until(t_node **a, t_node **b, t_node *stop)
{
	while (*a != stop->target && *b != stop)
		ps_rrr(a, b);
	ps_set_curr(*a);
	ps_set_curr(*b);
}

static void	ps_cheapest_to_top(t_node **b, t_node *to_top)
{
	if (to_top->above_med)
		while (*b != to_top)
			ps_rb(b);
	else
		while (*b != to_top)
			ps_rrb(b);
}

static void	ps_target_to_top(t_node **a, t_node *to_top)
{
	if (to_top->above_med)
		while (*a != to_top)
			ps_ra(a);
	else
		while (*a != to_top)
			ps_rra(a);
}

void	ps_push_prep(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = ps_find_cheapest(*b);
	if (!cheapest)
		return ;
	if (cheapest->above_med && cheapest->target->above_med)
		ps_rr_until(a, b, cheapest);
	else if (!(cheapest->above_med) && !(cheapest->target->above_med))
		ps_rrr_until(a, b, cheapest);
	ps_cheapest_to_top(b, cheapest);
	ps_target_to_top(a, cheapest->target);
	ps_push(b, a, 'a');
}
