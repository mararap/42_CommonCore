/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:59:44 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/27 23:20:50 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char **av)
{
    t_node		*a;
    t_node		*b;
    char		*input;
    char		**split_input;
    ssize_t		count;

    a = NULL;
    b = NULL;
	if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
		return (2);
    input = ps_input(av);
	if (!input)
		return (2);
	count = ps_wcount(input);
	split_input = ft_split(input, 32);
	if (!split_input)
		ps_free_all_exit(&a, &b, split_input, input);
	ps_stack_init(&a, split_input, count);
	if (ps_issorted(&a));
		ps_free_all_NULL(&a, &b, split_input, input);
	ps_sort(&a, &b);
	ps_free_all_NULL(&a, &b, split_input, input);
	return(0);
}
