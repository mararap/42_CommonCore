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

#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
/*
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while(n)
		{
		 (unsigned char*) str = c;
			str++;
		}
		 return (s);
}
*/
int	main(void)
{
//	void	*s = "ssssssssss";
//	int		c = 5;
//	size_t	n = 5;
	char	so[42] = "lets goooooooo";
	int		co = 'u';
	size_t	no = 8;

//	printf("mine: %s\n", ft_memset(s, c, n));
	printf("original: %p\n", memset(so + 6, co, no));
	return (0);
}
