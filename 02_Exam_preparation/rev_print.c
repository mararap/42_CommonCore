/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:13:08 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/15 15:55:14 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc != 2)
		return(write(1, "\n", 1), 0);
		while (argv[1][i])
		i++;
	while(i >= 0)
	{
		write(1, &argv[1][i], 1);
		i--;
	}
/*	while(i--)
	{
		write(1, &argv[1][i], 1);
	}*/
	write(1, "\0", 1);
	return(0);
}
