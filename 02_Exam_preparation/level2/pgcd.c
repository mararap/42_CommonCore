/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:30:09 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/24 14:30:10 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	gcd(int num1, int num2)
{
	int	small = 0;
	int	big = 0;
	int result = 0;

	if (num1 == num2)
		return(num1);
	else if (num1 < num2)
	{
		small = num1;
		big = num2;
	}
	else if (num2 < num1)
	{
		small = num2;
		big = num1;
	}
	result = big % small;
	if (result == 0)
		return(small);
	else if (result == 1)
		return (1);
	else
		result = gcd(small, result);
	return (result);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (printf("\n"), 1);

	int	output;
	int	num1 = atoi(av[1]);
	int	num2 = atoi(av[2]);

	output = gcd(num1, num2);
	printf("gcd = %d\n", output);
	return (0);
}
