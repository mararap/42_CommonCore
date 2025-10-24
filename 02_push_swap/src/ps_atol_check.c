/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atol_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:02:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/24 23:26:56 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ps_isvalid_sign(char c, char b)
{
	if (c == '-' && ft_isdigit(b))
		return (-1);
	if (c == '+' && ft_isdigit(b))
		return (1);
	return ((long)INT_MIN - 1);
}

long	ps_atol_check(char *str)
{
	ssize_t	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = (long)INT_MIN - 1;
	if (!str || str[i] == '\0')
		return(result);
	while (str[i] == ' ' || (str[i] <= '\r' && str[i] >= '\t') || str[i] == '"')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = ps_isvalid_sign(str[i], str[i + 1]);
	if (sign == ((long)INT_MIN - 1))
		return(result);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (result > 2147483647 || result < -2147483648)
		return((long)INT_MIN - 1);
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
