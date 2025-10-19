/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:10:05 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 22:57:08 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*input;
	char	**split_input;
	int		*value;
	int		size;
	int		i = 0;

	size = 0;
	if (ac < 2)
		return(2);
	input = ps_input(av);
	split_input = ft_split(input, 32);
	while (split_input[size])
		size++;
	value = ps_is_valid(split_input);
	if (!value)
		return(write(2, "Error\n", 6), 3);
	//printf("input = %s\n", input);
	while (i < size)
	{
		printf("%d\n", value[i]);
		i++;
	}
	return (0);
}