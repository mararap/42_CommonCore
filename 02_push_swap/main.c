/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:10:05 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/24 22:48:42 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*input;
	int		*value;
	ssize_t	size;
	ssize_t	i = 0;

	size = 0;
	if (ac < 2)
		return(2);
	input = ps_input(av);
	size = ps_wcount(input);
	av = ft_split(input, 32);
	value = ps_isvalid(av, size);
	if (!value)
		return(write(2, "Error\n", 6), 3);
	printf("input = %s\n", input);
	while (i < size)
	{
		printf("%d\n", value[i]);
		i++;
	}
	return (0);
}
