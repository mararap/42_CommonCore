/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:10:05 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/26 23:03:11 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*input = NULL;
	char	**split_input = NULL;
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	ssize_t	i = 0;
	ssize_t count = 0;

	if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
		return(2);
	input = ps_input(av);
	if (!input)
		return (2);
	count = ps_wcount(input);
	split_input = ft_split(input, 32);
	if (!split_input)
	{
		free(input);
		return (2);
	}
	a = ps_isvalid(split_input, count);
	if (!a)
	{
		ps_free_all(NULL, split_input, input);
		return(write(2, "Error\n", 6), 3);
	}
	b = ps_stack_init(count);
	if (!b)
		ps_free_all(a, split_input, input);
	a = ps_sorting(a);
	if (!a)
    {
        ps_free_all(NULL, split_input, input);
        return (write(2, "Error\n", 6), 3);
    }
	printf("input = %s\n", input);
	while (i < a->size)
	{
		printf("%d\n", a->value[i]);
		i++;
	}
	ps_free_all(a, split_input, input);
	return (0);
}
