/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:17:17 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/17 17:27:04 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int	i;
	char *dst;

	i = 0;
	while(src[i])
		i++;
	dst = malloc(i+1);
	i = 0;
	while(src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return(dst);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return(1);
	printf("ft-function: %s\n", ft_strdup(argv[1]));
	printf("libc-function: %s\n", strdup(argv[1]));
}
