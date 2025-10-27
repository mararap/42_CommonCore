/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:20:52 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/27 15:23:48 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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


static bool    ps_isspace(char c)
{
    if (c == ' ' || (c >= '\t' && c <= '\r'))
        return (true);
    return (false);
}

ssize_t     ps_wcount(char *s)
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
            if (!(ps_isspace(s[i])) && (ps_isspace(s[i + 1]) || s[i + 1] == '\0'))
                wcount++;
            i++;
        }
    }
	return (wcount);
}

// checks for duplicates//
static bool	ps_isdoub(t_node **stack, int value)
{
	while (stack)
	{
		if (stack[i]->value == value)
			return (true);
		i++;
	}
	return (false);
}
