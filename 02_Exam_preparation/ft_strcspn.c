/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:09:15 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/17 15:26:07 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	int	j;

	i = 0;
	// loop over *s
	while(s[i])
	{
	//start looping over *reject at 0 for every index of s
		j = 0;
		while(reject[j])
		{
			if (s[i] != reject[j])
				j++;
			else
				return(i);
		}
		i++;
	}
	return(i);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	printf("ft-function: %lu\n", ft_strcspn(argv[1], argv[2]));
	printf("libc-function: %lu\n", strcspn(argv[1], argv[2]));
	return (0);
}
