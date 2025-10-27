/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:02:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/27 15:25:04 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ps_isvalid_sign(char c, char b)
{
	if (c == '-' && ft_isdigit(b))
		return (-1);
	if (c == '+' && ft_isdigit(b))
		return (1);
	return ((long)INT_MIN - 1);
}

long	ps_atol_check(char *str)
{
	ssize_t	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = (long)INT_MIN - 1;
	if (!str || str[i] == '\0')
		return(result);
	while (str[i] == ' ' || (str[i] <= '\r' && str[i] >= '\t') || str[i] == '"')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = ps_isvalid_sign(str[i], str[i + 1]);
	if (sign == ((long)INT_MIN - 1))
		return(result);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (result > 2147483647 || result < -2147483648)
		return((long)INT_MIN - 1);
	return (result * sign);
}

t_node	*ps_find_min(t_node *stack)
{
	long	smallest;
	t_node	*result;
	
	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			result = stack;
		}
		stack = stack->next;
	}
	return (result);	
}

void	ps_append(t_node **stack, int value)
{
	t_node	*new;
	t_node	*last;

	if (!split_input || !*split_input)
		return ;
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	node->next = NULL;
	node->value = value;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = ps_find_last(*stack); // need to implement
		new->prev = last;
	}
}

void    ps_stack_init(t_node **stack, char *input, ssize_t count)
{
    char    **split_input;
	long    value;
    ssize_t i;
    
    i = 0;
	split_input = ft_split(input, ' ');
	if (!split_input)
		return ;
    while(split_input[i])
    {
        value = ps_atol_check(split_input[i]);
        if (value == (long)INT_MIN - 1)
            ps_free_all_exit;
		if (ps_isdoub(stack, (int)value))
			ps_free_all_exit;
		ps_append(stack, (int)value);
        i++;
    }
	ft_free_av(split_input);
}


/*
#include <stdio.h>

int	main(void)
{
	const char	str[42] = "3181651";

	printf("original function: %d\n", atoi(str));
	printf("my function: %d\n", ft_atoi(str));
	return (0);
}*/
