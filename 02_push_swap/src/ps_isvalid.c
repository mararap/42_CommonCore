/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:54:55 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 14:45:48 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_isvalid(char c, t_ps *stack_a, t_ps *stack_b)
{
	if ((c != ' ') && !ft_isdigit(c) && (c != '-') && (c != '+'))
		ps_handle_error(stack_a, stack_b);
}
long	ps_isvalid_sign(char c, char b)
{
	if (!ft_isdigit(b) || b == '0')
		return ((long)INT_MIN - 1);
	else
		return (c * 1);	
}
long	ps_doub(t_ps *arr, long num, int i)
{
	int	j;
	
	j = 0;
	while(j < i)
	{
		if(arr[j].value == num)
			return(1);
		j++;
	}
	return (0);
}
