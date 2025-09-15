/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 21:54:24 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/14 22:17:28 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	j = 0;
	int	i = 0;
	int	rep = 1;
	char *abc = "abcdefghijklmnopqrstuvwxyz";
	if (argc != 2)
		write(1, "\n", 1);
	while(argv[1][i])
	{
		while(argv[1][i] != abc[j])
			j++;
		rep = j+1;
		while(rep > 0)
		{
			write(1, &argv[1][i], 1);
			rep--;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
