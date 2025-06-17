/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:05:17 by marapovi          #+#    #+#             */
/*   Updated: 2025/06/17 10:05:20 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
 	printf("\nlength is: %d\n", ft_printf("testing %s, that's it", ""));
 	printf("\nlength is: %d\n",    printf("testing %s, that's it", ""));

	int og_res;
	int my_res;
	og_res = printf("Og: %c %s %d %i %u %p %x %X %%%%%", 15, " ", 0, -2147483648, 2147483649, NULL, 255, 255);
	printf("\n");
	my_res = ft_printf("My: %c %s %d %i %u %p %x %X %%%%%", 15, " ", 0, -2147483648, 2147483649, NULL, 255, 255);
	printf("\n");


	printf("OG Res: %d\n", og_res);
	printf("My Res: %d\n", my_res);

    return (0);
}
