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

#include "libftprintf.h"

static int	ft_intlen(int n)
{
	long int	nbr;
	int			count;

	nbr = (long int)n;
	count = 0;
	if (n == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	ft_putint(int n)
{
	long int	nbr;
	int			count;

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
		ft_putint(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
	count = ft_intlen(n);
	return (count);
}
