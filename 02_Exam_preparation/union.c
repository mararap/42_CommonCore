/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:40:18 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/18 14:05:22 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_no_doub(char *str, char c, int curr)
{
	int i = 0;

	while(i < curr)
	{
		if(str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	curr;
	int		i = 0;
	int		last;

	if (ac != 3)
		return(write(1, "\n", 1));
	while(av[1][i])
	{
		curr = av[1][i];
		if (ft_no_doub(av[1], curr, i) == 0)
			write(1, &curr, 1);
		i++;
	}
	last = i;
	i = 0;
	while(av[2][i])
	{
		curr = av[2][i];
		if ((ft_no_doub(av[1], curr, last) == 0)
			&& (ft_no_doub(av[2], curr, i) == 0))
			write(1, &curr, 1);
		i++;
	}
	write(1, "\n", 1);
	return(0);
}
