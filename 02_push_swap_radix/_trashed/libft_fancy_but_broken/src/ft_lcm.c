/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:59:24 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/11 18:03:37 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lcm(unsigned int a, unsigned int b)
{
	unsigned int	result = 0;
	if (a == 0 || b == 0)
		return (0);
	result = (a / ft_gcd(a, b)) * b;
	return (result);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char** av)
{
	if (ac != 3)
		return (printf("wrong number of arguments\n"), 1);
	unsigned int	a = (unsigned int) atoi(av[1]);
	unsigned int	b = (unsigned int) atoi(av[2]);
	unsigned int	result = 0;
	unsigned int	gcd = 0;
	gcd = ft_gcd(a, b);
	printf("gcd = %d\n", gcd);
	result = lcm(a, b);
	printf("lcm = %d\n", result);
	return (0);
}*/
