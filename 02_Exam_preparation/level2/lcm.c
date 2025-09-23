/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:49:38 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/22 17:47:09 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_hcf(unsigned int a, unsigned int b)
{
	unsigned int	hcf = 0;
	unsigned int	big = 0;
	unsigned int	small = 0;
	unsigned int	remain = 0;
	if (a > b)
		big = a, small = b;
	else if (b > a)
		big = b, small = a;
	remain = big % small;
	if (remain == 1)
		hcf = 1;
	else if (remain == 0)
		hcf = small;
	else
		hcf = ft_hcf(small, remain);
	return (hcf);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	lcm;
	unsigned int	hcf;

	hcf = ft_hcf(a, b);
	lcm = (a * b) / hcf;
	return (lcm);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char** av)
{
	if (ac != 3)
		return (printf("wrong number of arguments\n"), 1);
	unsigned int	a = (unsigned int) atoi(av[1]);
	unsigned int	b = (unsigned int) atoi(av[2]);
	unsigned int	result = 0;
	unsigned int	hcf = 0;
	hcf = ft_hcf(a, b);
	printf("hcf = %d\n", hcf);
	result = lcm(a, b);
	printf("lcm = %d\n", result);
	return (0);
}
