/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:42:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/06/06 10:42:44 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libftprintf.h"

static int nbrlen (int n)
{
	size_t		amount;
	long int	nbr;
	
	nbr = (long int) n;
	amount = 0;
	if (n < 0)
	{
		nbr *= -1;
		amount++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		amount++;
	}
	amount++;
	return amount;
}

int	ft_putnbr(int n)
{
	long int	nbr;
	int			count;
		
	count = nbrlen(n);
	nbr = (long int) n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr <= 9)
		ft_putchar(nbr + 48);
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
	return (count);
}
