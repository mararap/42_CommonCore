/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:42 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/21 16:52:16 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_lower(char c)
{
	if(c >= 97 && c <= 122)
		return (1);
	return(0);
}

int	main(int ac, char **av)
{
	int		i;
	size_t	j;
	int		len;
	char	c;
//	char	*camel;

	i = 0;
	j = 0;
	len = 0;
	while(av[1][len])
		len++;
	if (ac == 2)
	{
		while(av[1])
		{
			if(check_lower(av[1][i]) == 1)
			{
				write(1, &av[1][i], 1);
				j++;
			}
			else if(av[1][i] == 95)
			{
				i++;
				c = (av[1][i] - 32);
				write(1, &c, 1);
				j++;
			}
			else
				return(write(1, "\n", 1), 1);
			i++;
		}
	}
	return(write(1, "\n", 1), 0);
}

