/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:44:53 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/27 23:27:58 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ps_set_curr(t_node *stack)
{
    ssize_t i;
    ssize_t median;

    i = 0;
    if (!stack)
        return ;
    median = ps_stacklen(stack) / 2;
    while (stack)
    {
        stack->curr_pos = i;
        if (i <= median)
            stack->above_med = true;
        else
            stack->above_med = false;
        stack = stack->next;
        i++;
    }
}

static void    ps_find_target(t_node *a, t_node *b)
{
    t_node  *curr_a;
    t_node  *target;
    long    target_index;

    while (b)
    {
        target_index = LONG_MAX;
        curr_a = a;
        while (curr_a)
        {
            if (curr_a->value > b->value && curr_a->value < target_index)
            {
                target_index = curr_a->value;
                target = curr_a;
            }
            curr_a = curr_a->next;
        }
        if (target_index = LONG_MAX)
            b->target = ps_find_min(a);
        else
            b->target = target;
        b = b->next;
    }
}

static void    ps_calc_cost(t_node *a, t_node *b)
{
    ssize_t len_a;
    ssize_t len_b;

    len_a = ps_stacklen(a);
    len_b = ps_stacklen(b);
    while (b)
    {
        b->cost = b->curr_pos;
        if (!(b->above_med))
            b->cost = len_b - (b->curr_pos);
        if (b->target->above_med)
            b->cost = b->cost + b->target->curr_pos;
        else
            b->cost = b->cost + len_a - (b->target->curr_pos);
        b = b->next;
    }
}

static void    ps_find_cheapest(t_node *b)
{
    long    cheapest_value;
    t_node  *cheapest_node;

    if (!b)
        return ;
    cheapest_value = LONG_MAX;
    while (b)
    {
        if (b->cost < cheapest_value)
        {
            cheapest_value = b->cost;
            cheapest_node = b;
        }
        b = b->next;
    }
    cheapest_node->cheapest = true;
}

void    ps_nodes_init(t_node *a, t_node *b)
{
    ps_set_curr(a);
    ps_set_curr(b);
    ps_find_target(a, b);
    ps_calc_cost(a, b);
    ps_find_cheapest(b);
}