/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:59:44 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/28 01:01:31 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char **av)
{
    t_node		*a;
    t_node		*b;
    char		*input;

    a = NULL;
    b = NULL;
	if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
		return (2);
    input = ps_input(av);
	if (!input)
		return (2);
	ps_stack_init(&a, input);
	if (ps_issorted(a))
	{
		ps_free_all(&a, &b, NULL, input);
		return (0);
	}
	ps_sort(&a, &b);
	ps_free_all(&a, &b, NULL, input);
	return(0);
}
