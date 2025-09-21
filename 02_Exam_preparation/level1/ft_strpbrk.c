/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:30:03 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/17 17:58:50 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;

	while (s2[j])
	{
		while(s1[i])
		{
			if (s2[j] == s1[i])
				return((char *)&s1[i]);
			i++;
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return(1);
	printf("ft-function: %s\n", ft_strpbrk(argv[1], argv[2]));
	printf("libc-function: %s\n", strpbrk(argv[1], argv[2]));
	return(0);
}
