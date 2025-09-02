/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_shft_YTCodeVault.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:13:04 by marapovi          #+#    #+#             */
/*   Updated: 2025/08/12 12:21:16 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause")*/

int	main (int argc, char *argv[])
{
	unsigned int a = 1;
	printf("Left shifted by 1: %d\n", a << 1); // a * 2^1
	printf("Left shifted by 1: %d\n", a << 2); // a * 2^2
	printf("Left shifted by 1: %d\n", a << 3); // a * 2^3
	printf("Left shifted by 1: %d\n", a << 4); // a * 2^4
	
	return 0;
}
/*
int	main (int argc, char *argv[])
{
	int a = -100000000;
	// 5  =  0101
	// 10 =  1010
	// 20 = 10100
	unsigned int i; //only for unsigned integers!
	for (i = 0; i < 32; i++)
	{
		printf("Left shifted by %02d: %08x | %u\n", i, a << i, a << i);
		// left shifted = a * 2^i
		printf("Right shifted by %02d: %08x | %u\n", i, a >> i, a >> i);
		// right shifted = a / 2^i
	}
	return 0;
}*/
*/
int	main (int argc, char *argv[])
{
	int a = 100000000;
	//  5 =  0101
	// 10 =  1010
	// 20 = 10100
	//  4 =  0100
	a <<= 2;
	printf("%d\n", a);
	
	return 0;
}*/
