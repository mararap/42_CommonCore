/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:59:15 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/26 23:19:48 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
    int             value;
    int             curr_pos;
    int             final_index; // what is this for? rename?
    int             push_price;
    bool            above_med;
    bool            cheapest;
    struct s_node   *target;
    struct s_node   *prev;    
    struct s_node   *next;
}               t_node;

#endif