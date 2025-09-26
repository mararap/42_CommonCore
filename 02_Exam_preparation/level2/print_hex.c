/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:35:38 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/26 19:25:11 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_atoi(char *str)
{
	int				i = 0;
	unsigned int	num = 0;
	unsigned int	factor = 1;
	while (str[i])
		i++;
	i--;
	if (i < 0)
		return (write(1, "string is empty\n", 16), 1);
	while (i >= 0)
	{
		num = num + ((str[i] - 48) * factor);
		factor = factor * 10;
		i--;
		if (str[i] < '0' || str[i] > '9')
			return(write(1, "\ninvalid input\n", 15), 1);
	}
	return (num);
}

void	put_hex(unsigned int nbr)
{
	char	*hex_base = "0123456789abcdef";

	if (nbr >= 16)
		put_hex(nbr / 16);
	nbr = hex_base[nbr % 16];
	write (1, &nbr, 1);	
}

int	main (int ac, char **av)
{
	if (ac != 2)
		return(write(1, "wrong number of arguments\n", 27), 1);
	unsigned int	num;
	num = ft_atoi(av[1]);
	if (!num)
		return (write(1, "ft_atoi error\n", 14), 1);
	if (num > 4294967295 || num < 0)
		return(write(1, "invalid input\n", 15), 1);
	put_hex(num);
	write(1, "\n", 1);
	return (0);
}
