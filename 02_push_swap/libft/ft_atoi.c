/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:21:43 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/05 21:26:20 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check out libft bonus//

#include <push_swap.h>

int	ft_atoi(const char *str)
{
	size_t		i;
	char		sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == ' ' || (str[i] <= '\r' && str[i] >= '\t'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

