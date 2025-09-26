/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:08:13 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/26 14:59:52 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char	result = 0;

	i = 7;
	while(i >= 0)
	{
		result = (result << 1) | (octet & 1);
		octet = octet >> 1;
		i--;
	}
	return(result);
}

//    	octet & 1, octet >> 1			   (result << 1) | (octet & 1)
// 1st	000000100 & 000000001 = 00000000 | 00000000
// 2nd	000000010 & 000000001 = 00000000 | 00000000
// 3rd	000000001 & 000000001 = 00000001 | 00000001
// 4th	000000000 & 000000001 = 00000000 | 00000010
// 5th							00000000 | 00000100
// 6th							00000000 | 00001000
// 7th							00000000 | 00010000
// 8th iteration				00000000 | 00100000
    
int	main(void)
{
	int	i = 7;
	unsigned char octet = 4;
	unsigned char res = reverse_bits(4);
	
	while(i >= 0)
	{
		if((octet >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
	write(1, "\n", 1);
	i = 7;
	while(i >= 0)
	{
		if((res >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}
