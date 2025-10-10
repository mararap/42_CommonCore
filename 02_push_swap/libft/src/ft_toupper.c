/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:43:38 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/10 21:59:55 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc >= 'a' && uc <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int c;

	c = 'm';
	printf("mine: %d\n", ft_toupper(c));
	printf("original: %d\n", toupper(c));
	return (0);
}*/
