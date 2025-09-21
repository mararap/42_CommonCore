/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:48:40 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/16 14:47:16 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	times_ten;
	int	str_start;
	int	sign;

	i = 0;
	times_ten = 1;
	sign = 1;
	num = 0;
	while(str[i] && str[i] == ' ')
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	str_start = i;
	if(str[i] < 48 || str[i] > 58)
		return(num);
	while(str[i])
		i++;
	i--;
	while(i >= str_start)
	{
		num += ((str[i] - 48) * times_ten);
		times_ten *= 10;
		i--;
	}
	num *= sign;
	return(num);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	printf("ft-function: %d\n", ft_atoi(argv[1]));
	printf("stdlib-function: %d\n", atoi(argv[1]));
	return(0);
}*/
