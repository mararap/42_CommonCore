/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:22:33 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/28 00:19:04 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ps_push(t_node **src, t_node **dest, char dest_name)
{
    t_node  *to_push;

    if (!*src)
        return ;
    to_push = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    to_push->prev = NULL;
    if (NULL == *dest)
    {
        *dest = to_push;
        to_push->next = NULL;
    }
    else
    {
        to_push->next = *dest;
        to_push->next->prev = to_push;
        *dest = to_push;
    }
    write (1, "p", 1);
    write (1, &dest_name, 1);
    write (1, "\n", 1);
}
