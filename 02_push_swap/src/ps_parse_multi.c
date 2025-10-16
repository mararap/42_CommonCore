/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:26:26 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/16 13:29:31 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps *ps_parse_multi(t_ps *stack, char **arr, int *error)
{
	long	temp;
	int		i;

	i = 0;
	stack->item = (int *)malloc(stack->len * sizeof(int *));
	if (!stack->item)
	{
		*error = 1;
		ps_handle_error(*error, stack);
	}
	while (i < stack->len)
	{
		temp = ps_atol_check(arr[i], &error);
		if (*error == 1)
			ps_handle_error(&error, stack);
		stack->item[i] = (int)temp;
		if (ps_doub(stack->item, stack->item[i], (int)i))
			ps_handle_error(&error, stack);
		i++;
	}
	return (stack);
}
