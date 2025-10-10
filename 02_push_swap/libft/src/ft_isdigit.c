/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:51:55 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/10 21:55:34 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isdigit(int i)
{
	unsigned char	c;

	c = (unsigned char)i;
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
 	printf("my function: %d\n", ft_isdigit(-2147483649));
	printf("original function: %d\n", isdigit(-2147483649));
	return (0);
}*/
