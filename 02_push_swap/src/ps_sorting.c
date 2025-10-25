/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:19:36 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/25 18:33:44 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ps_issorted(t_stack *stack)
{
	ssize_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->value[i] > stack->value[i + 1])
			return (false);
		i++;
	}
	return (true);
}
t_stack *ps_sorting(t_stack *a)
{	
	if (a)
	{
		if (ps_issorted(a))
			return (a);
/*		else if (a->size <= 3)
		{
			// ps_sort_3(a); // to be implemented
		}
		else if (a->size <= 5)
		{
			// ps_sort_5(a); // to be implemented
		}
		else
		{
			// ps_sort_large(a); // to be implemented
		}
		return (a);
	}*/
	}
	return (NULL);
}
