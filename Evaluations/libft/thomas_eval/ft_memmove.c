/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:06:02 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/15 15:06:06 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d > s)
	{
		while (len != 0)
		{
			len--;
			d[len] = s[len];
		}
		return (d);
	}
	else
	{
		ft_memcpy(dst, src, len);
		return (d);
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[42] = "";
	char	dsto[42] = "";
	char	src[] = "y";
	char	srco[] = "y";
	size_t	len = 1;

	printf("my function: %s\n", (char *)ft_memmove(dst, src, len));
	printf("original function: %s\n", (char *)memmove(dsto, srco, len));
}*/
