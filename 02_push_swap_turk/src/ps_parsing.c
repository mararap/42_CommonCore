/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:20:52 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/16 19:35:46 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// takes av and joins all the arguments to one string //
char	*ps_input(char **av)
{
	char	*str;
	char	*temp;
	ssize_t	i;

	i = 1;
	if (!av[i] || !av[i][0])
		return (NULL);
	str = ft_strjoin(av[i++], " ");
	if (!str)
		return (NULL);
	while (av[i] != NULL)
	{
		temp = ft_strjoin(str, av[i]);
		free(str);
		if (!temp)
			return (NULL);
		str = ft_strjoin(temp, " ");
		free(temp);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}

// check if char is whitespace character //
bool	ps_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (true);
	return (false);
}

// count number of words in string //
ssize_t	ps_wcount(char *s)
{
	ssize_t	i;
	ssize_t	wcount;

	wcount = 0;
	i = 0;
	if (!s)
	{
		return (-1);
	}
	else
	{
		while (s[i])
		{
			if (!(ps_space(s[i])) && (ps_space(s[i + 1]) || s[i + 1] == '\0'))
				wcount++;
			i++;
		}
	}
	return (wcount);
}

// checks for duplicates in linked list//
bool	ps_isdoub(t_node **stack, int num)
{
	t_node	*curr;

	if (!stack || !*stack)
		return (false);
	curr = *stack;
	while (curr)
	{
		if (curr->value == num)
			return (true);
		curr = curr->next;
	}
	return (false);
}
