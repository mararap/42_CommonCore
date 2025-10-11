/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:26:26 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/11 15:23:54 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int *ps_parse_multi(int len, char **arr, int *error)
{
	int	i;
	int	j;
	long	*result;

	i = 0;
	j = 0;
	result = (long *)malloc(len * sizeof(int *));
	if (!result)
		*error = 1;
	while (arr[j] && result[i] && i < len)
	{
		result[i] = ps_atol_check(arr[j], error);
		if (!result || result[i] > 2147483647 || result[i] < -2147483648)
			*error = 1;
		i++;
		j++;
	}
	result[i] = '\0';
	return ((int *)result);
}
