/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:54:26 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/19 10:54:29 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intsize(int n)
{
	size_t	size;
	long	ln;

	size = 0;
	ln = n;
	if (n < 0)
		ln = ln * (-1);
	while (ln > 0)
	{
		ln = ln / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*newstr;
	int		sign;
	long	ln;
	size_t	size;

	sign = 1;
	ln = n;
	size = ft_intsize(n);
	if (n <= 0)
	{
		size = size + 1;
		sign = sign * (-1);
		ln = ln * sign;
	}
	newstr = ft_calloc(size + 1, sizeof(char));
	while (size > 0)
	{
		newstr[size - 1] = ((ln % 10) + 48);
		ln = (ln / 10);
		size--;
	}
	if (n < 0)
		newstr[0] = '-';
	return (newstr);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n = (0);

	printf("newstr: %s\n", ft_itoa(n));
	return (0);
}*/
