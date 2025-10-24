/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:59:26 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 21:39:26 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
t_ps	*ps_create_stack_a(int ac, char **av)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		l = 0;
	char 	**temp;
	t_ps	*stack = NULL;
	int		len;

	i = 1;
	while (av && av[i] && i <= (ac - 1))
	{
		j = 0;
		temp = ft_split(av[i], 32);
		len = ps_arr_of_str_len(temp);
		while (j < len)
		{
			if (ps_atol_check(temp[j]) == ((long)INT_MIN - 1)
				|| ps_doub(stack, ps_atol_check(temp[j]), k))
			{
				free(stack);
				ps_free_str_arr(temp);
				write (2, "Error\n", 6);
				exit(2);
			}
			stack[l].value = ps_atol_check(temp[j]);
			k++;
			l++;
		}
		i++;
	}
	stack[k].value = '\0';
	
	return(stack);
}*/
char **ps_parse_str(char *str, t_ps *stack_a, t_ps *stack_b)
{
	int i;
	char *temp;
	char **str_split;

	i = 0;
	// allocate space for temporary char-string "temp"
//	temp = (char *)(malloc(sizeof(char) * (ft_strlen(str) + 1)));
//	if (!temp)
//		ps_handle_error(stack_a, stack_b);
	// check for validity while copying chars to temp
	while (str[i])
	{
		ps_isvalid(str[i], stack_a, stack_b);
		temp[i] = str[i];
		i++;
	}
	// set last character to be '\0'
	temp[i] = '\0';
	// split the copied string temp into an array of char-str "str_split"
	str_split = ft_split((char const *)temp, 32);
	if (!str_split)
			ps_handle_error(stack_a, stack_b);
//	free (temp);
	return (str_split);
}
t_ps *ps_parse_splits(char **arr, int len)
{
	int i;
	t_ps	*stack;

	/* len is number of elements in arr (for multi-arg usage this should be ac - 1) */
	i = 0;
	while (i < len)
	{
		long value = ps_atol_check(arr[i]);
		if (value == ((long)INT_MIN - 1))
		{
			write(2, "Error\n", 6);
			exit(2);
		}
		/* check duplicate among already filled entries (0..i-1) */
		if (ps_doub(stack, value, i))
		{
			write(2, "Error\n", 6);
			exit(2);
		}
		stack[i].value = value;
		stack[i].index = -1;
		i++;
	}
	return (stack);
}


