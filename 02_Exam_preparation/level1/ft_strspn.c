/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:26:35 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/17 17:02:27 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	// looping over *s
	while (s[i])
	{
		check = 0;
		j = 0;
		while(accept[j])
		{
			if (s[i] == accept[j])
				check = 1;
			j++;
		}
		if(check == 0)
			return(i);
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return(1);
	printf("ft-function: %zu\n", ft_strspn(argv[1], argv[2]));
	printf("libc-function: %lu\n", strspn(argv[1], argv[2]));
}
