/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:58 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/14 14:53:01 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] && i + j < len && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	*big = "Hello world where are you now";
	char	*little = "where are you";
	size_t	n = 42;
	char	*myresult = ft_strnstr(big, little, n);
	char	*originalresult = strnstr(big, little, n);
	
	printf("myresult: %c\n", *myresult);
	printf("original result: %c\n", *originalresult);
	return (0);
}*/
