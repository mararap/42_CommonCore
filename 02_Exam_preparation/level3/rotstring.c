/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 00:45:17 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/30 01:02:55 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rotstring(char *str)
{
	int	i;
	int	j;
	
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	j = i;
	while(str[i])
	{
		while (str[i] && (str[i] != ' ' || str[i] != '\t'))
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while ((str[i] && (str[i] != ' ' && str[i] != '\t')) &&
				str[i - 1] == ' ' || str[i - 1] == '\t'))
		{
			while (str[i] && (str[i] != ' ' || str[i] != '\t'))
			{
				write (1, &str[i], 1);
				i++;
			}
		}
	while (str[j] && str[j] != ' ' && str[j] != '\t')
	{
		write (1, &str[j], 1);
		j++;
	}
}

int	main (int ac, char **av)
{
	if (ac >= 1)
	{
		rotstring(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}	
