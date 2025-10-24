/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:59:48 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/24 23:16:09 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdbool.h>

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

// checks if the char *str input is valid and converts it to int array //
int	*ps_isvalid(char **av, ssize_t size)
{
	ssize_t i;
	int	*stack;

	i = 0;
	if (size <= 0)
		return (NULL);
	stack = malloc((size * sizeof(int)));
	if (!stack)
		return(NULL);
	while (i < size && av[i] != NULL)
	{
		stack[i] = (int)ps_atol_check(av[i]);
		if (ps_isdoub(stack, stack[i], i))
		{
			free(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

bool	ps_isdoub(int *arr, int num, ssize_t i)
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
