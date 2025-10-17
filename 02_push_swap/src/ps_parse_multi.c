/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:26:26 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/17 19:46:24 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps *ps_parse_multi(t_ps *stack, char **arr)
{
	long	temp;
	int		i;

	i = 0;
	stack->item = (int *)malloc(stack->len * sizeof(int));
	if (!stack->item)
		ps_handle_error(5);
	while (i < stack->len)
	{
		temp = ps_atol_check(arr[i]);
		stack->item[i] = (int)temp;
		ps_doub(stack->item, stack->item[i], (int)i);
		i++;
	}
	return (stack);
}
