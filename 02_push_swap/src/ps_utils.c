/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:14:11 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 15:17:20 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ps_arr_of_str_len(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}
/*void	ps_free_stack(t_ps *stack)
{
	if (stack->value)
		free(*(stack->value));
//	if (stack->len)
//		free(stack->len);
	if (stack->index)
		free(stack.index);
	free(stack);
}*/

void	ps_handle_error(t_ps *stack_a, t_ps *stack_b)
{
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	
	write(2, "Error\n", 6);
	exit(2);
}
