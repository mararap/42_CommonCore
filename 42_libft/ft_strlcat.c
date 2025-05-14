/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:46:53 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/07 10:47:00 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dl;
	size_t	sl;

	i = 0;
	j = 0;
	sl = ft_strlen(src);
	dl = ft_strlen(dest);
	if (size == 0)
		return (sl);
	if ((size <= dl) && (size >= sl))
		return (sl + size);
	while (dest[j] != '\0')
		j++;
	printf("j after first loop: %zu\n", j);
	while ((src[i]) && ((dl + sl + 1) <= size) && (j <= (dl + sl)))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (ft_strlen(dest));
}
/*
int main(void)
{
	char	desto[] = "12345";
	char	*srco = "6789";
	size_t	sizeo = 20;
	
	char	destm[] = "12345";
	char	*srcm = "6789";
	size_t	sizem = 20;

	printf("original: %zu\n", strlcat(desto, srco, sizeo));
	printf("original: %s\n", desto);
	printf("mine: %zu\n", ft_strlcat(destm, srcm, sizem));
	printf("mine: %s\n", destm);
	return (0);
}*/
