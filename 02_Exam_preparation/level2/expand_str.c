/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:38:14 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/21 20:51:35 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main (int ac, char **av)
{
	int	i = 0;
	char *str = av[1];

	if (ac != 2)
		return (write(1, "\n", 1), -1);
	while(str[i])
	{
		if (str[i] <= 32)
			i++;
		else
		{
			write (1, &str[i], 1);
			i++;
			if (str[i] && str[i] <= 32 && (str[i + 1] > 32))
				write (1, "   ", 3);
		}
	}
	return (write(1, "\n", 1), 0);
}
