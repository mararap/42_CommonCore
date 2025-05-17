/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:01:43 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/17 18:01:45 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*newstr;

	i = 0;
	newstr = ft_calloc(ft_strlen(s) + 1, 1);
	if (newstr == NULL)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(0, s[i]);
		i++;
	}
	return (newstr);
}
/*
#include <stdio.h>

char	ft_ttoupper(unsigned int i, char c)
{
	(void) i;
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

int	main(void)
{
	char *str = "Hallo";
	char *out;
	out = ft_strmapi(str, ttoupper);
	printf("out: %s\n", out);
	return (0);
}*/
