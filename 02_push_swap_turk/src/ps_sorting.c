/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:28:58 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/27 12:08:51 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool ps_issorted(t_node *stack)
{
    if (!stack)
        return (true);
    while (stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
}
static t_node *ps_find_max(t_node *stack)
{
    int     max_value;
    t_node  *max_node;

    if (!stack)
        return (NULL);
    max_node = INT_MIN;
    while (stack)
    {
        if (stack->value > max_value)
        {
            max_value = stack->value;
            max_node = stack;
        }            
        stack = stack->next;
    }
    return (max_node);
}
void    ps_micro_sort(t_node **stack, char stack_name)
{
    t_node  *max_node;

    max_node = ps_find_max(*stack);
    if (*stack == max_node)
        ps_rotate(a, 'a'); // need to implement
    else if ((*stack)->next == max_node)
        ps_rotate_reverse(a, 'a'); // need to implement
    if ((*stack)->value > (*stack)->next->value)
        ps_swap(a, 'a'); // need to implement
}

void    ps_sort_5(t_node **a, t_node **b)
{
    while (ps_stack_size(*a) > 3) // need to implement
    {
        ps_init_nodes(*a, *b); // need to implement
        ps_finish_rotation(a, ps_find_smallest(*a), 'a'); // need to implement // need to implement ps_find_smallest
        ps_push(b, a, 'b'); // need to implement
    }
}
/*
void    ps_sorting(t_node **a, t_node **b)
{
    if (ps_issorted(*a))
        return ;
    if ((*a)->next == NULL)
        return ;
    if ((*a)->next->next == NULL)
    {
        if ((*a)->value > (*a)->next->value)
            ps_swap(a, 'a');
        return ;
    }
    if ((*a)->next->next->next == NULL)
    {
        ps_micro_sort(a, 'a');
        return ;
    }
}*/