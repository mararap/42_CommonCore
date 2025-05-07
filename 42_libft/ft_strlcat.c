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
#include "ft_strlen.c"

size_t	ft_strlcat(char *dest, char *src, size_t size)
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
	while ((src[i]) && (j <= (size - dl - 1)) && (j <= (dl + sl)))
	{
		dest[j] = src[i];
		i++;
	}
	dest[j] = '\0';
	return (ft_strlen(dest));
}
/*
int main(void)
{
	char	dest[7] = "12345";
	char	*src = "6789";
	size_t	size = 20;

	printf("%zu\n", strlcat(dest, src, size));
	printf("%s\n", dest);
	printf("%zu\n", ft_strlcat(dest, src, size));
	printf("%s\n", dest);
	return (0);
}*/
