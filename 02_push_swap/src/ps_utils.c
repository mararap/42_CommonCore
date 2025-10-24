/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:40:24 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/24 23:09:01 by marapovi         ###   ########.fr       */
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

