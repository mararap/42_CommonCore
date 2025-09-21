/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:31:15 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/19 20:40:42 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i = 0;

	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main (int ac, char **av)
{
	int	i = 0;
	int	j = 0;
	int	len = 0;

	if(ac != 3)
		return (write(1, "\n", 1), -1);
	while(av[1][len])
		len++;
	while(av[1][i] && av[2][j])
	{
		if(av[1][i] == av[2][j])
			i++;
		j++;
	}
	if (i == len)
		ft_putstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
