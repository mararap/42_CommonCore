/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:40:24 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/28 21:33:52 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_free_stack(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	ft_free_av(char **av)
{
	ssize_t	i;

	i = 0;
	if (!av)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	ps_error_exit(t_node **a, t_node **b, char **av, char *input)
{
	if (a)
		ps_free_stack(a);
	if (b)
		ps_free_stack(b);
	if (av)
		ft_free_av(av);
	if (input)
		free(input);
	write (2, "Error\n", 6);
	exit(1);
}

void	ps_free_all(t_node **a, t_node **b, char **av, char *input)
{
	if (a)
		ps_free_stack(a);
	if (b)
		ps_free_stack(b);
	if (av)
		ft_free_av(av);
	if (input)
		free(input);
}
