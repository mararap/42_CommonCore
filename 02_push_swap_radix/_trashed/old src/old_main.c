/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:52 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 21:46:05 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char    **input_str;
	t_ps    *stack_a = NULL;
	t_ps    *stack_b = NULL;
	size_t  i = 0;
	size_t  len = 0;

	if (ac == 1 || av[1][0] == '\0' || av[1][0] == 32)
		return (2);
	/* only allocate stack_b if needed later; parsing functions allocate stack_a */
	if (ac == 2)
	{
		input_str = ps_parse_str(av[1], stack_a, stack_b);
//		len = ps_arr_of_str_len(input_str);
		stack_a = ps_parse_multi(stack_a, input_str, (int)len);
		ps_free_str_arr(input_str);
	}
	else if (ac > 2)
	{
		/* pass pointer to first value (av + 1) and count ac - 1 */
		stack_a = ps_parse_multi(stack_a, av + 1, ac - 1);
		len = (size_t)(ac - 1);
		if (!stack_a)
			ps_handle_error(stack_a, stack_b);
	}
	printf("stack_a =");
	while (i < len && stack_a)
	{
		printf(" %ld", stack_a[i].value);
		i++;
	}
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	return (0);
}
