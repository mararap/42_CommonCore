/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:45:38 by marapovi          #+#    #+#             */
/*   Updated: 2025/08/11 16:13:17 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

int	main(void)
{
	int	i;

	i = 1;
	while(i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
}












/*int	main (void)
{
	void	ft_putnbr(int i)
	{
		if (i > 9)
			ft_putnbr(i / 10);
		write (1, &"0123456789"[i % 10], 1)
		return(0);
	}
	while (i <= 100)
	{
		int	i;

		i = 1;
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else
			ft_putnbr(i);
		i++;
		write (1, "\n", 1);
	}
	return (0);
}*/
