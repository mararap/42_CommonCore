/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:19:36 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/24 22:19:57 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ps_issorted(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] > arr[i + 1])
			return (false);
		i++;
	}
	return (true);
}