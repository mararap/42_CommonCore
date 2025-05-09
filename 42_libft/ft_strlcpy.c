/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:20:13 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/02 13:20:19 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <bsd/string.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy (char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;

	if (size == 0)
		return ft_strlen(src);
	while ((i < (size-1)) && (src[i]))
			{
				(dest[i]) = (src[i]);
					i++;
			}
			dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char dest[25] = "nowtestme";
	char *src = "testmetestme";
	size_t size = 4;

	printf("%zu\n", strlcpy(dest, src, size));
	printf("%s\n", dest);
	printf("%zu\n", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	return(0);
}*/
