/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:09:00 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/08 10:09:06 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t	i;

	str = s;
	i = 0;
	while((str[i]) && (i <= n))
		{
		 str[i] = c;
			i++;
		}
		 return (s);
}

int	main(void)
{
//	void	*s = "ssssssssss";
//	int		c = 5;
//	size_t	n = 5;
	void	*so = "ssssssssss";
	int		co = 5;
	size_t	no = 5;

//	printf("mine: %s\n", ft_memset(s, c, n));
	printf("original: %zu\n", memset(so, co, no));
	return (0);
}
