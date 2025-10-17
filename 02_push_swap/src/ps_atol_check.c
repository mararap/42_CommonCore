/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atol_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:02:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/17 22:36:18 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ps_atol_check(char *str)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!str || str[i] == '\0')
		return(false);
	while (str[i] == ' ' || (str[i] <= '\r' && str[i] >= '\t'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = ps_isvalid_sign(str[i], str[i + 1]);
	if (sign == 0)
		return(false);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (result > 2147483647 || result < -2147483648)
		return(false);
	return (result * sign);
}


/*
#include <stdio.h>

int	main(void)
{
	const char	str[42] = "3181651";

	printf("original function: %d\n", atoi(str));
	printf("my function: %d\n", ft_atoi(str));
	return (0);
}*/
