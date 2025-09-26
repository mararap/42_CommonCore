/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:01:05 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/25 17:00:16 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int main ()
{
	int	i = 0;
	unsigned char	octet = 4;
	unsigned char	swapped = swap_bits(4);
	while(i < 8)
	{
		if ((octet >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	while (i < 8)
	{
		if ((swapped >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
}
