/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:55:16 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/15 20:33:16 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int	argc, char **argv)
{
	int		i;
	char	c;

	i = 0;
	c = argv[1][i];

	if(argc != 2)
		return (write(1, "\n", 1), 1);
	while(argv[1][i])
	{
		if((c >= 65 && c <= 89) || (c >= 97 && c <= 121))
			c += 1;
		else if (c == 90 || c == 122)
			c -= 25;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
