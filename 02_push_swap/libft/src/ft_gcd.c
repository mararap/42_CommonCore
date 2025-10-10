/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:58:24 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/10 21:51:55 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

unsigned int	ft_gcd(unsigned int a, unsigned int b)
{
	unsigned int	temp = 0;

	while (b != 0)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return (a);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (printf("\n"), 1);

	unsigned int	a;
	unsigned int	b;
	unsigned int	temp;

	a = (unsigned int)atoi(av[1]);
	b = (unsigned int)atoi(av[2]);

	while (b != 0)
	{
		temp = b;
		b = a % temp;
		a = temp;
	}
	printf("%d\n", a);
	return (0);
}*/
