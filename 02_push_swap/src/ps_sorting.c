/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:19:36 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/25 11:18:12 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ps_issorted(t_stack stack)
{
	ssize_t	i;

	i = 0;
	while (stack.value[i] && i < stack.size - 1)
	{
		if (stack.value[i] > stack.value[i + 1])
			return (false);
		i++;
	}
	return (true);
}

