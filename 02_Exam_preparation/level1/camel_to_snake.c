/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:26:30 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/16 12:12:52 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
//	int		len;
//	int		cap;
//	char	*snake;

	i = 0;
//	len = 1;
//	cap = 0;
	if (ac != 2)
		return(write(1, "\n", 1), 1);
/*	while(av[1][i])
	{
		if (av[1][i] >= 65 && av[1][i] <= 90)
			cap++;
		i++;
	}
	i--;
	if (av[1][i] >= 65 && av[1][i] <= 90)
		cap--;
	snake = malloc(i+cap+1);
	i = 0;*/
	while (av[1][i])
	{
		if (av[1][i] >= 65 && av[1][i] <= 90)
		{
			write(1, "_", 1);
			av[1][i] += 32;
			write(1, &av[1][i], 1);
		}
		else
			write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return(0);
}


