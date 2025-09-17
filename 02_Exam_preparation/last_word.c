/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:47:21 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/17 19:34:00 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int i = 0;
	int end;
	char *str = av[1];

	if(ac != 2)
		return(write(1, "\n", 1));
	while(str[i])
		i++;
	i--;
	printf("i25 = %d\n", i);
	while (str[i] == 32 || str[i] == 9)
		i--;
	end = i;
	printf("i28 = %d\n", i);
	while(i >= 0 && !(str[i] == 32 || str[i] == 9))
		i--;
	i++;
	printf("i31 = %d\n", i);
	while(str[i] && i <= end)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
