/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:14:25 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/15 10:14:29 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == uc)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s = "testing my function";
	int	c = '\0';

	printf("my function: %s\n", ft_strrchr(s, c));
	printf("original function: %s\n", strrchr(s, c));
	return(0);
}*/
