/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:51:55 by marapovi          #+#    #+#             */
/*   Updated: 2025/04/23 16:52:04 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
