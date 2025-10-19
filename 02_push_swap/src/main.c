/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:52 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 15:02:10 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**input_str; // or (void *)malloc(sizeof(char *)); ?
	t_ps	*stack_a = NULL;
	t_ps	*stack_b = NULL;
//	int		error;
	int		i = 0;
	int		len;

//	error = 0;
	if (ac == 1 || av[1][0] == '\0' || av[1][0] == 32)
		return(2);
	stack_a = (t_ps *)malloc((ac - 1) * sizeof(t_ps));
	if (!stack_a)
		return(2);
	stack_b = (t_ps *)malloc((ac -1) * sizeof(t_ps));
	if (!stack_b)
		return(free(stack_a), 2);
	else if (ac == 2)
	{
		input_str = ps_parse_one(av[1], stack_a, stack_b);
		len = ps_arr_of_str_len(input_str);
		ps_parse_multi(stack_a, input_str, len);
		ps_free_str_arr(input_str);
	}
	else if (ac > 2)
	{
		stack_a = ps_parse_multi(stack_a, av, ac - 1);
		if (!stack_a)
			ps_handle_error(stack_a, stack_b);
	}
	printf ("stack_a =");
	while (i < (ac -1))
	{
		printf(" %ld", stack_a[i].value);
		i++;
	}
	free(stack_a);
	free(stack_b);
	return(0);
}
