/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:41:21 by marapovi          #+#    #+#             */
/*   Updated: 2025/08/11 14:48:05 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc,char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		write(1, "\n", 1);
	while ((argv[1][i] == 32) || (argv[1][i] == 9))
		i++;
	while(argv[1][i])
	{
		if((argv[1][i] >= 65 && argv[1][i] <= 90) || (argv[1][i] >= 79 && argv[1][i] <= 122))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		else
			break ;
	}
	write(1, "\n", 1);
	return(0);
}

/*int main (int ac, char *av[])
{
	if (ac == 2)
	{
		unsigned int	i;

		i = 0;
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		while ((av[1][i] != 32 && av[1][i] != 9) && av[1][i] != '\0')
			write (1, &av[1][i++], 1);
	}
	write (1, "\n", 1);
		return (0);
}*/
