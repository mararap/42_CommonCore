/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:26:26 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 15:49:26 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps *ps_parse_multi(t_ps *stack_a, char **arr, int len)
{
	int		i;

	i = 1;
	stack_a = malloc((len + 1) * sizeof(t_ps));
	if (!stack_a)
		return(NULL);
	while (i < len)
	{
		if (ps_atol_check(arr[i]) == ((long)INT_MIN - 1))
		{
			ps_free_str_arr(arr);
			free(stack_a);
			exit(2);
		}	
		stack_a[i].value = ps_atol_check(arr[i]);
		ps_doub(stack_a, stack_a[i].value, i);
			if(ps_doub(stack_a, stack_a[i].value, i))
			{
				ps_free_str_arr(arr);
				free(stack_a);
				exit(2);
			}	
		i++;
	}
	return (stack_a);
}
