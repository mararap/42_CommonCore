/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:58:30 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/21 19:27:45 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int		i = 0;
	char	sign = 1;
	int		result = 0;

	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while(str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return(result * sign);
}

int	ft_is_prime(int nbr)
{
	if (nbr < 2)
		return(0);
	int	i = 2;
	while (i <= nbr / 2)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return(1);
}

void	ft_putnbr(int n)
{
	long int	nbr;
	char		c;
	
	nbr = (long int) n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if(nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + 48;
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac != 2 || ft_atoi(av[1]) <= 0)
		return (write(1, "0\n", 2), -1);

	int	n = ft_atoi(av[1]);
	int	sum = 0;

	while(n > 1)
	{
		if (ft_is_prime(n))
			sum += n;
		n--;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return(0);
}
