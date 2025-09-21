/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:30:51 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/17 18:43:08 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int j = 0;
	char *s1 = av[1];
	char *s2 = av[2];
	
	if (ac != 3)
		return (write(1, "\n", 1), 1);
	while(s1[i])
	{
		while(s2[j])
		{
			if(s1[i] == s2[j])
			{
				write(1, &s1[i], 1);
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
