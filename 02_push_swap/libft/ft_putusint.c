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

static int	ft_usintlen(unsigned int u)
{
	unsigned long int	nbr;
	int					count;

	nbr = (unsigned long int)u;
	count = 0;
	if (u == 0)
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

int	ft_putusint(unsigned int u)
{
	unsigned long int	nbr;
	int			count;

	nbr = (unsigned long int)u;
	if (nbr <= 9)
		ft_putchar(nbr + 48);
	if (nbr > 9)
	{
		ft_putusint(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
	count = ft_usintlen(u);
	return (count);
}

#include <stdio.h>

int main(void)
{
	ft_putusint(-4568);
	return(0);
}
