/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:02:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/28 11:43:06 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	ps_isvalid_sign(char c, char d)
{
	if (c == '-' && ft_isdigit(d))
		return (-1);
	if (c == '+' && ft_isdigit(d))
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
	if (!str || str[i] == '\0')
		return((long)INT_MIN - 1);
	while (ps_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = ps_isvalid_sign(str[i], str[i + 1]);
	if (sign == ((long)INT_MIN - 1) || !ft_isdigit(str[i + 1]))
		return((long)INT_MIN - 1);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i] - 48;
	if (str[i] != '\0' || (result * sign) > INT_MAX || (result * sign) < INT_MIN)
		return((long)INT_MIN - 1);
	return (result * sign);
}

void	ps_append(t_node **stack, int value)
{
	t_node	*new;
	t_node	*tail;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->next = NULL;
	new->value = value;
	new->curr_pos = 0;
	new->above_med = false;
	new->cheapest = false;
	new->target = NULL;	
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		tail = ps_find_tail(*stack);
		new->prev = tail;
		tail->next = new;
	}
}

void    ps_stack_init(t_node **stack, char *input)
{
    char    **split_input;
	long    value;
    ssize_t i;
    
    i = 0;
	split_input = ft_split(input, ' ');
	if (!split_input || !split_input[0] || !split_input[0][0])
		ps_error_exit(stack, NULL, split_input, input);
    while(split_input[i])
    {
        value = ps_atol_check(split_input[i]);
        if (value == (long)INT_MIN - 1)
            ps_error_exit(stack, NULL, split_input, input);
		if (ps_isdoub(stack, (int)value))
			ps_error_exit(stack, NULL, split_input, input);
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
