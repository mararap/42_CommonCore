/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:19:36 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/26 22:20:56 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ps_issorted(t_stack *stack)
{
	ssize_t	i;

	i = 0;
	if (!stack || stack->size <= 1)
		return (true);
	while (i < stack->size - 1)
	{
		if (stack->value[i] > stack->value[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	ps_isreversesorted(t_stack *stack)
{
	ssize_t	i;

	i = 0;
	if (!stack || stack->size <= 1)
		return (true);
	while (i < stack->size - 1)
	{
		if (stack->value[i] < stack->value[i + 1])
			return (false);
		i++;
	}
	return (true);
}

void	ps_sort_3(stack *stack, char stack_name)
{
	if (a->value[0] > a->value[1] && a->value[0] > a->value[2])
	{
		ps_rotate(a, 'a');
		if (a->value[0] > a->value[1])
			ps_swap(a, 'a');
	}
	else if (a->value[1] > a->value[0] && a->value[1] > a->value[2])
	{
		ps_rrotate(a, 'a');
		if (a->value[0] > a->value[1])
			ps_swap(a, 'a');
	}
	else
	{
		if (a->value[0] > a->value[1])
			ps_swap(a, 'a');
	}
}
void	ps_microsort(t_stack *stack, char stack_name)
{
	if (!a || a->size <= 1)
		return (true);
	else if (a->size == 2)
	{
		if (a->value[0] > a->value[1])
			ps_swap(a, 'a');
	}
	else if (a->size == 3)
	{
		ps_sort_3(a, 'a');
	}
	return(ps_issorted(a));
}

t_stack *ps_sorting(t_stack *stack, char stack_name)
{	
	if (!a)
		return (NULL);
	else if (ps_issorted(a))
		return (a);
	else if (a->size <= 3)
		ps_microsort(a);
	else if (a->size <= 5)
	{
		// ps_sort_5(a); // to be implemented
	}
	else
	{
		// ps_sort_large(a); // to be implemented
	}
	return (a);
}

