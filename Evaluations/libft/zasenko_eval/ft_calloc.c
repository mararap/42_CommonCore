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

#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total;

	if (!size || !nmemb)
		return (malloc(0));
	total = (nmemb * size);
	if (total / nmemb != size)
		return (NULL);
	ptr = NULL;//malloc(total);
	if (ptr == NULL)
		return (printf("ERROR\n"), NULL);
	ft_bzero(ptr, total);
	return ((void *)ptr);
}


// int	main(void)
// {
// 	size_t	nmemb = 42;
// 	size_t	size = sizeof(int);

// 	char *s;
// 	s = ft_calloc(nmemb, size);
// 	printf("[%s]\n", s);
// 	//printf("my function: %p\n", ft_calloc(nmemb, size));
// 	//printf("original function: %p\n", calloc(nmemb, size));
// 	free(s);
// 	return (0);
// }
