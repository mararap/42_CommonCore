/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:13:08 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/16 13:07:12 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main (int ac, char **av)
{
	int	first;
	int	third;
	int	result;

	if (ac != 4)
		return(write(1, "\n", 1));
	first = atoi(av[1]);
	third = atoi(av[3]);
	result = 0;
	if (av[2][0] == '+')
		result = first + third;
	else if (av[2][0] == '-')
		result = first - third;
	else if (av[2][0] == '*')
		result = first * third;
	else if (av[2][0] == '/')
		result = first / third;
	else if (av[2][0] == '%')
		result = first % third;
	printf("%i\n", result);
	return (result);
}
