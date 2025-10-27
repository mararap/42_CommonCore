/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:59:44 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/27 13:27:11 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char **av)
{
    t_stack_node    *a;
    t_stack_node    *b;
    char            *input;
    char            **split_input;
    ssize_t         count;

    a = NULL;
    b = NULL;
	if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
		return(2);
    input = ps_input(av);
	else if (!input)
		return (2);
	count = ps_wcount(input);
	split_input = ft_split(input, 32);
	if (!split_input)
	{
		free(input);
		return (2);
	}
	ps_stack_init(&a, split_input, count); // need to implement
	ps_doub(); // need to implement
	ps_sort(&a, &b, count); // need to implement
	ps_free_all(&a, &b, split_input, input); // need to implement
    return (0);
}
