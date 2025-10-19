/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:59:26 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 17:41:35 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*create_stack_a(int ac, char **av, int *len)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char 	**temp;
	t_ps	*stack;

	i = 0;
	while (av && av[i] && i <= (ac - 1))
	{
		j = 0;
		temp = ft_split(av[i], '"');
		len = ps_arr_of_str_len(temp);
		while (j < len)
		{
			if (ps_atol_check(temp[j][k]) == ((long)INT_MIN - 1)
				|| ps_doub(temp[j], temp[j][k], k))
			{
				free(stack);
				ps_free_str_arr(temp);
				write (2, "Error\n", 6);
				exit(2);
			}
			stack[l].value = ps_atol_check(temp[j][k]);
			k++;
			l++;
		}
		i++;
	}
	stack[k].value = '\0';
	len = k + 1;
	return(stack);
}

static int ps_arr_len(int len, char**)

