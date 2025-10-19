/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:59:48 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 22:52:41 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ps_input(char **av)
{
	char	*str;
	char 	*temp;
	int		i;

	i = 1;
	str = ft_strjoin(av[i++], " ");
	while (av[i] != NULL)
	{
		temp = ft_strjoin(str, av[i]);
		str = ft_strjoin(temp, " ");
		i++;
	}
	return (str);
}
int	*ps_is_valid(char **split_input)
{
	int	size;
	int i;
	int	*stack;

	i = 0;
	size = 0;
	while(split_input[size] != NULL)
		size++;
	stack = malloc(size * sizeof(int));
	while (split_input[i] != NULL)
	{
		stack[i] = (int)ps_atol_check(split_input[i]);
		if (ps_doub(stack, stack[i], i))
			return (NULL);
		i++;
	}
	return (stack);
}
bool	ps_doub(int *arr, int num, int i)
{
	int	j;
	
	j = 0;
	while(j < i)
	{
		if(arr[j] == num)
			return(true);
		j++;
	}
	return (false);
}