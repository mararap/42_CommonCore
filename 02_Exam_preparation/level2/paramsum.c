/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:10:09 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/23 12:23:51 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int	i)
{
	if (i >= 10)
		ft_putnbr (i / 10);
	char c = i % 10 + '0';
	write (1, &c, 1);
}

int	main(int ac, char **av)
{
	(void)av;

	if (ac == 1)
		return (write(1, "0\n", 2), 1);
	ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return (0);
}
