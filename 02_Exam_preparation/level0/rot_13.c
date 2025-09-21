/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:40:20 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/15 17:53:08 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char	**argv)
{
	int	i;

	if(argc != 2)
	{
		write(1, "\n", 1);
		return(1);
	}
	i = 0;
	while(argv[1][i])
	{
		if((argv[1][i] >= 78 && argv[1][i]<= 90) ||
			(argv[1][i] >= 111 && argv[1][i] <= 122))
			argv[1][i] -= 13;
		else if((argv[1][i] >= 65 && argv[1][i] <= 77) ||
			(argv[1][i] >= 97 && argv[1][i] <= 109))
			argv[1][i] += 13;
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

/*
int	main (int ac, char **av)
{
	if (ac == 2)
	{
		unsigned int	i;

		i = 0;
		while (av[1][i])
		{
			if ((av[1][i] >= 77 && av[1][i] <= 90) || (av[1][i] >= 111 && av[1][i] <= 122))
				av[1][i] -= 13;
			else if ((av[1][i] >= 65 && av[1][i] <= 76) || (av[1][i] >= 97 && av[1][i] <= 110))
				av[1][i] += 13;
			write (1, &av[1][i], 1);
			i++;
		}
	}
	return(0);
}*/
