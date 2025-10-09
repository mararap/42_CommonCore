/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:01:45 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/09 16:01:47 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int* tab, unsigned int len)
{
	unsigned int	i = 0;
	int	result = 0;

	if (!tab || !tab[i])
		return (0);
	result = tab[i];
	while (i < len)
	{
		if (tab[i] > result)
			result = tab[i];
		i++;
	}
	return (result);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int				result = 0;
	unsigned int	i = 0;
	unsigned int	len = 0;

	len = ac - 1;
	int	*tab = malloc(len * sizeof(int));
	if (!tab)
		return (1);
	while (i < len)
	{
		tab[i] = atoi(av[i + 1]);
		i++;
	}
	result = max(tab, len);
	printf("max = %d\n", result);
	free (tab);
	return (0);
}*/
