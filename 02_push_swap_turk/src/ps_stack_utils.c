/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:15:37 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/27 23:07:32 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node  *ps_find_tail(t_node *head)
{
    if (!head)
        return (NULL);
    while (head->next)
        head = head->next;
    return (head);
}

t_node	*ps_find_min(t_node *stack)
{
	long	min_value;
	t_node	*result;
	
	if (!stack)
		return (NULL);
	min_value = LONG_MAX;
    result = stack;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			result = stack;
		}
		stack = stack->next;
	}
	return (result);	
}

t_node  *ps_find_max(t_node *stack)
{
    int     max_value;
    t_node  *result;

    if (!stack)
        return (NULL);
    max_value = INT_MIN;
    result = stack;
    while (stack)
    {
        if (stack->value > max_value)
        {
            max_value = stack->value;
            result = stack;
        }
        stack = stack->next;
    }
    return (result);
}

ssize_t ps_stacklen(t_node *stack)
{
    ssize_t len;

    if (!stack)
        return (0);
    len = 0;
    while (stack)
    {
        stack = stack->next;
        len++;
    }
    return (len);
}