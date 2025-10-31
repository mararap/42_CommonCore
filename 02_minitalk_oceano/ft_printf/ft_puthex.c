/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:13:23 by marapovi          #+#    #+#             */
/*   Updated: 2025/06/10 15:13:27 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_hexlen(unsigned int x)
{
	unsigned long int	nbr;
	int					count;

	nbr = (unsigned long int)x;
	count = 1;
	if (x == 0)
		return (1);
	while (nbr >= 16)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned int x, int c)
{
	char				*hex;
	unsigned long int	nbr;
	int					result;

	result = ft_hexlen(x);
	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	nbr = x;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16, c);
	}
	ft_putchar(hex[nbr % 16]);
	return (result);
}
