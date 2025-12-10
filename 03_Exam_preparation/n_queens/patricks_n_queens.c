/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:04:18 by pjelinek          #+#    #+#             */
/*   Updated: 2025/10/06 23:53:56 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	check_position(int *pos, int col, int row)
{
	int	i = 0;

	while (i < col)
	{
		if (pos[i] == row || (ft_abs(row - pos[i]) == (col - i)))
			return (0);
		i++;
	}
	return (1);
}

void	place_queens(int *pos, int col, int nb)
{
	int 	row;
	int 	i;

	if (nb == col)
	{
		i = 0;
		while (i < nb)
		{
			printf("%d", pos[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	row = 0;
	while (row < nb)
	{
		if (check_position(pos, col, row))
		{
			pos[col] = row;
			place_queens(pos, col + 1, nb);
		}
		row++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
/* 	int i = 0;
	while (av[1][i])
	{
		if (av[1][i] < '0' || av[1][i] > '9')
			return (printf("FAIL"), 1);
		i++;
	} */
	int nb = atoi(av[1]);
	int *p = malloc(sizeof(int) * nb);
	if (!p)
		return (1);
	place_queens(p, 0, nb);
	free(p);
	return (0);
}

