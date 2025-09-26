/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:38:16 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/24 11:23:08 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return(write(1, "\n", 1), 1);
	char	*s1 = av[1];
	char	*s2 = av[2];
	int	i = 0;
	int	j = 0;
	int	len = 0;
	int	result = '0';

	while(s1[len])
		len++;
	while(s2[j] && s1[i])
	{
		if (s2[j] == s1[i])
			i++;
		j++;
	}
	if (i == len)
		result = '1';
	write(1, &result, 1);
	write(1, "\n", 1);
	return (0);
}
