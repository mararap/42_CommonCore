/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:32:54 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/16 10:32:56 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	nmemb, size_t size)
{
	unsigned char	*ptr;

	if (size == 0 || (((size_t)-1 / size) < nmemb))
	{
		return (NULL);
	}
	ptr = malloc(size * nmemb);
	ft_bzero(ptr, size * nmemb);
	return ((void *)ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	size_t	nmemb = 42;
	size_t	size = sizeof(int);
	
	printf("my function: %p\n", ft_calloc(nmemb, size));
	printf("original function: %p\n", calloc(nmemb, size));
	return (0);
}*/
