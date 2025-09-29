/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:10:43 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/29 17:52:38 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	num;
	// set i to smallest prime number
	i = 2;
	// check if number of arguments is valid
	if (ac != 2)
	{
		printf("\n");
		return (1);
	}
	// convert char input to int using atoi
	num = atoi(av[1]);
	// check if number is just "1". if so, print.
	if (num == 1)
		printf("1");
	// loop increasing i until it reaches num
	while (i <= num)
	{
		// if first divisor is found, print it.
		if (num % i == 0)
		{
			printf("%d", i);
			// print "*" only if it's not the last one
			if (num != i)
			{
				printf("*");
			}
			// then set num to be num divided by i
			num /= i;
		}
		// if i is not a valid divisor, increase it by 1 and start over
		else
			i++;
	}
	// print new line only at the very end, when while-loop is finished
	printf("\n");
	return (0);
}
