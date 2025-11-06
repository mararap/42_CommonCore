/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:00:21 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/03 13:35:19 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static long	mt_isvalid_sign(char *str, ssize_t i)
{
	if (str[i] == 45 || str[i] == 43)
	{
		if (ft_isdigit(str[i + 1]))
		{
			if (str[i] == 45)
				return (-1);
		}
		else
			return ((long)INT_MIN - 1);
	}
	return (1);
}
static bool	mt_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (true);
	return (false);
}

static ssize_t	mt_skip_spaces(char *str)
{
	ssize_t	i;

	i = 0;
	while (mt_space(str[i]))
		i++;
	return (i);
}

long	mt_atol(char *str)
{
	long	result;
	long	sign;
	ssize_t	i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str || !str[0])
		return ((long)INT_MIN - 1);
	i = mt_skip_spaces(str);
	sign = mt_isvalid_sign(str, i);
	if (sign == ((long)INT_MIN - 1))
		return ((long)INT_MIN - 1);
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (str[i] != '\0' && !mt_space(str[i]))
		return ((long)INT_MIN - 1);
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		return ((long)INT_MIN - 1);
	return (result * sign);
}

