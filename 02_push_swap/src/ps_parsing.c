/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:59:48 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/25 12:55:19 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	ps_isdoub(int *arr, int num, ssize_t i)
{
	ssize_t	j;
	
	j = 0;
	while(j < i)
	{
		if(arr[j] == num)
			return(true);
		j++;
	}
	return (false);
}

// takes av and joins all the arguments to one string //
char *ps_input(char **av)
{
	char	*str;
	char 	*temp;
	ssize_t		i;

	i = 1;
	if (!av[i])
		return (NULL);
	str = ft_strjoin(av[i++], " ");
	while (av[i] != NULL)
	{
		temp = ft_strjoin(str, av[i]);
		free(str);
		str = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (str);
}

// checks if the char *str input is valid and converts it to t_stack stack //
t_stack	*ps_isvalid(char **av, ssize_t size)
{
	t_stack		*stack;
	ssize_t		i;
	long		tmp;
	
	i = 0;
	if (size <= 0 || !av)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (free(av), NULL);
	stack->size = size;
	stack->value = ft_calloc(size, sizeof(int));
	stack->curr_pos = ft_calloc(size, sizeof(ssize_t));
	if (!stack->value || !stack->curr_pos)
		return ((t_stack *)ps_free_NULL(stack, av, NULL));
	while (i < size && av[i] != NULL)
	{
		tmp = ps_atol_check(av[i]);
		if (tmp == ((long)INT_MIN - 1))
			return ((t_stack *)ps_free_NULL(stack, av, NULL));
		stack->value[i] = (int)tmp;
		if (ps_isdoub(stack->value, stack->value[i], i))
			return ((t_stack *)ps_free_NULL(stack, av, NULL));
		i++;
	}
	return (stack);
}

