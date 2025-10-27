/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_reverserotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:46:31 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/27 18:30:16 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ps_rrotate(t_node **stack)
{
    t_node   *last;
    ssize_t  len;
    
    len = ps_stacklen(*stack);
    if (!*stack || !stack || len == 1)
        return ;
    last = ps_find_tail(*stack);
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    *stack = last;
    last->next->prev = last;
}

void    ps_rra(t_node **a)
{
    ps_rrotate(*a);
    write (1, "rra\n", 4);
}

void    ps_rrb(t_node **b)
{
    ps_rrotate(*b);
    write (1, "rrb\n", 4);
}

void    ps_rrr(t_node **a, t_node **b)
{
    ps_rrotate(*a);
    ps_rrotate(*b);
    write (1, "rrr\n", 4);
}
