/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:48:21 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/11 18:03:37 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_valid(char c, int str_base)
{
    char    *lower_base = "0123456789abcdef";
    char    *upper_base = "0123456789ABCDEF";
    int     i = 0;

    while(i < str_base)
    {
        if (c == lower_base[i] || c == upper_base[i])
            return (i);
        i++;
    }
    return (-1);
}
int ft_atoi_base(const char *str, int str_base)
{
    int i = 0; 
    int sign = 1;
    int result = 0;

    while (ft_is_space(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {   
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] && is_valid(str[i], str_base) != -1)
    {
		result = result * str_base + is_valid(str[i], str_base);
        i++;
    }
    return (result * sign);
}
