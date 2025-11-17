/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:59:44 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/17 12:58:53 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*input;

	a = NULL;
	b = NULL;
	input = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		ps_error_exit(&a, &b, NULL, NULL);
	input = ps_input(av);
	if (!input)
		ps_error_exit(&a, &b, NULL, NULL);
	ps_stack_init(&a, input);
	if (ps_issorted(a))
	{
		ps_free_all(&a, &b, NULL, input);
		return (0);
	}
	ps_sort(&a, &b);
	ps_free_all(&a, &b, NULL, input);
	return (0);
}
