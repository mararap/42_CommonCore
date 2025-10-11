/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:52 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/11 14:07:07 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	**input_str = NULL;
	int		*stack_a = NULL;
	int		error;

	i = 0;
	error = 0;
	if (ac == 1)
		error = 1;
	else if (ac == 2)
	{
		input_str = ps_parse_one(av[1], &error);
		stack_a = ps_parse_multi(ac - 1, input_str, &error);
		ps_free_str_arr(input_str);
	}
	else if (ac > 2)
		stack_a = ps_parse_multi(ac - 1, av, &error);
	if (error)
		ft_error_exit();
	ft_printf("stack_a = %s\n", stack_a);
	free(stack_a);
	return(0);
}
