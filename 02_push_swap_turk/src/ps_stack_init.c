/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:02:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/15 18:02:53 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	ps_isvalid_sign(char *str, ssize_t i)
{
	if (str[i] == 45 || str[i] == 43)
	{
		if (ft_isdigit(str[i + 1]))
		{
			if (str[i] == 45)
				return (-1);
		}
		else
			return ((long)INT_MIN - 1);
	}
	return (1);
}

static ssize_t	ps_skip_spaces(char *str)
{
	ssize_t	i;

	i = 0;
	while (ps_space(str[i]))
		i++;
	return (i);
}

long	ps_atol_check(char *str)
{
	long	result;
	long	sign;
	ssize_t	i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str || !str[0])
		return ((long)INT_MIN - 1);
	i = ps_skip_spaces(str);
	sign = ps_isvalid_sign(str, i);
	if (sign == ((long)INT_MIN - 1))
		return ((long)INT_MIN - 1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (str[i] != '\0' && !ps_space(str[i]))
		return ((long)INT_MIN - 1);
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		return ((long)INT_MIN - 1);
	return (result * sign);
}

void	ps_append(t_node **stack, int value)
{
	t_node	*new;
	t_node	*tail;

	new = NULL;
	tail = NULL;
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

void	ps_stack_init(t_node **stack, char *input)
{
	char	**split_input;
	long	value;
	ssize_t	i;

	i = 0;
	value = 0;
	split_input = NULL;
	split_input = ft_split(input, ' ');
	if (!split_input || !split_input[0] || !split_input[0][0])
		ps_error_exit(stack, NULL, split_input, input);
	while (split_input[i])
	{
		if (ft_strlen(split_input[i]) > 11)
			ps_error_exit(stack, NULL, split_input, input);
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
