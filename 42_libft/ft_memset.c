/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:24:51 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/12 11:25:55 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n)
	{
		*str = c;
		str++;
		n--;
	}
	return (s);
}
/*
#include <string.h>
#include <stdio.h>
#include <strings.h>

int	main(void)
{
	char s[42] = "lets goooooooo";
	int		c = 'u';
	size_t	n = 8;
	
	char	so[42] = "lets goooooooo";
	int		co = 'u';
	size_t	no = 8;

	printf("mine: %s\n", (char *)ft_memset(s, c, n));
	printf("original: %s\n", (char *)memset(so, co, no));
	return (0);
}*/
