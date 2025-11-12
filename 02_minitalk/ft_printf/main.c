/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:05:17 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/12 11:32:41 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	printf("\nlength is: %d\n", ft_printf("testing %s, that's it", "string"));
	printf("\nlength is: %d\n", printf("testing %s, that's it", "string"));
	return (0);
}
