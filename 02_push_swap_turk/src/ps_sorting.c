/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:54:14 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/28 13:11:45 by marapovi         ###   ########.fr       */
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

static void    ps_micro_sort(t_node **a)
{
    t_node  *max_node;
    
    max_node = NULL;
    max_node = ps_find_max(*a);
    if (*a == max_node)
        ps_ra(a);
    else if ((*a)->next == max_node)
        ps_rra(a);
    if ((*a)->value > (*a)->next->value)
        ps_sa(a);
}

static void    ps_minisort(t_node **a, t_node **b)
{
    ssize_t len_a;
    ssize_t len_b;
    t_node  *min;
    
    min = NULL;
    len_a = ps_stacklen(*a);
    while (len_a > 3)
    {
        ps_set_curr(*a);
        min = ps_find_min(*a);
        if (min->above_med)
            while (*a != min)
                ps_ra(a);
        else
            while (*a != min)
                ps_rra(a);
        ps_push(a, b, 'b');
        len_a--;
    }
    ps_micro_sort(a);
    len_b = ps_stacklen(*b);
    while (len_b > 0)
    {
        ps_push(b, a, 'a');
        len_b--;
    }
}
void    ps_sort(t_node **a, t_node **b)
{
    ssize_t len_a;
    
    len_a = ps_stacklen(*a);
    if (len_a <= 5)
        ps_minisort(a, b);
    else
    {
        while (len_a > 3)
        {
            ps_push(a, b, 'b');
            len_a--;
        }
        ps_micro_sort(a);
        while (*b)
        {
            ps_nodes_init(*a, *b);
            ps_push_prep(a, b);
        }
    }
    ps_set_curr(*a);
    ps_min_to_top(a);
}

void    ps_min_to_top(t_node **a)
{
    t_node  *min;

    min = NULL;
    ps_set_curr(*a);
    min = ps_find_min(*a);
    if (min->above_med)
        while (*a != min)
            ps_ra(a);
    else
        while (*a != min)
            ps_rra(a);    
}
