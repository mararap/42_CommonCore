/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:52 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/17 19:45:04 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**input_str; // or (void *)malloc(sizeof(char *)); ?
	t_ps	stack_a;
//	t_ps	stack_b = NULL;
	int		error;
	int		i = 0;

	error = 0;
	if (ac == 1)
		error = 1;
	else if (ac == 2)
	{
		input_str = ps_parse_one(av[1]);
		stack_a.len = ps_arr_of_str_len(input_str);
		ps_parse_multi(&stack_a, input_str);
		ps_free_str_arr(input_str);
	}
	else if (ac > 2)
	{
		stack_a.len = ac - 1;
		ps_parse_multi(&stack_a, av + 1);
	}
	printf ("stack_a =");
	while (i < stack_a.len)
	{
		printf(" %d", stack_a.item[i]);
		i++;
	}
	free(stack_a.item);
	return(0);
}
