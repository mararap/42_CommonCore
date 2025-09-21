/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:30:03 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/17 14:06:05 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	r;

	i = 0;

	while (s1[i] && s2[i])
	{
		r = s1[i] - s2[i];
		i++;
	}
	return(r);
}

#include <stdio.h>

int	main (int argc, char **argv)
{
	if (argc != 3)
		return(1);

	printf("%d\n", ft_strcmp(argv[1], argv[2]));
	return(0);
}
