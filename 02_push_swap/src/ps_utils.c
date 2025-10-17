/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:14:11 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/17 22:19:46 by marapovi         ###   ########.fr       */
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
void	ps_free_stack(t_ps *stack)
{
	if (stack->item)
		free(stack->item);
	if (stack->len)
		free(stack->len);
	free(stack);
}

void	ps_handle_error(t_ps *stack_a, t_ps *stack_b)
{
	if (stack_a)
		ps_free_stack(stack_a);
	if (stack_b)
		ps_free_stack(stack_b);
	
	write(2, "Error\n", 6);
	exit(2);
}
