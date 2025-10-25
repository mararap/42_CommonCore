/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:40:24 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/25 17:50:52 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void    ft_free_av(char **av)
{
    ssize_t i;

    i = 0;
    if (!av)
        return ;
    while (av[i])
    {
        free(av[i]);
        i++;
    }
    free(av);
}
void    ps_free_all(t_stack *stack, char **av, char *input)
{
    if (stack)
    {
            free(stack->curr_pos);
            free(stack->value);
            free(stack);
    }
    if (av)
        ft_free_av(av);
    if (input)
        free(input);
}
t_stack  *ps_free_NULL(t_stack *stack, char **av, char *input)
{
    ps_free_all(stack, av, input);
    return (NULL);
}

