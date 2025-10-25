/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:10:05 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/25 12:44:54 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*input = NULL;
	char	**split_input = NULL;
	t_stack	*a = NULL;
//	t_stack	b = {0};
	ssize_t	i = 0;
	ssize_t count = 0;

	if (ac < 2)
		return(2);
	input = ps_input(av);
	if (!input)
		return (2);
	count = ps_wcount(input);
	split_input = ft_split(input, 32);
	if (!split_input)
		return (free(input), 2);
	a = ps_isvalid(split_input, count);
	if (!a)
		return(write(2, "Error\n", 6), 3);
	
	printf("input = %s\n", input);
	while (i < a->size)
	{
		printf("%d\n", a->value[i]);
		i++;
	}
	ps_free_all(a, split_input, input);
	return (0);
}
