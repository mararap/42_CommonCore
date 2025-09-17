/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:00:14 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/17 18:29:05 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrev(char *str)
{
	int i = 0;
	int j = 0;
	char c;

	c = str[0];
	while(str[i])
		i++;
	j = i - 1;
	i = 0;
	while(i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return(str);
}

int	main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	printf("revstr: %s\n", ft_strrev(argv[1]));
}
