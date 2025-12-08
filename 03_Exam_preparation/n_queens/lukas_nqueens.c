/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lukas'nqueens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwittwer <lwittwer@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:32:02 by lwittwer          #+#    #+#             */
/*   Updated: 2025/12/01 21:37:03 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*board;
int	N;

int	isSafe(int r, int c)
{
	int	i = 0;
	int	pc;
	while (i < r)
	{
		pc = board[i];
		if (pc == c)
			return (0);
		if (abs(pc - c) == abs(i - r))
			return (0);
		i++;
	}
	return (1);
}

void	printSolution()
{
	int	i;
	int	j;
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (board[i] == j)
				printf("%d", j);
			j++;
		}
		i++;
	}
	printf("\n");
}

void	solveNQueens(int row)
{
	int	col;

	if (row == N)
	{
		printSolution();
		return;
	}
	col = 0;
	while (col < N)
	{
		if (isSafe(row, col))
		{
			board[row] = col;
			solveNQueens(row + 1);
		}
		col++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <N>\n", argv[0]);
		return (1);
	}
	N = atoi(argv[1]);
	if (N < 1)
	{
		fprintf(stderr, "Invalid N\n");
		return (1);
	}
	board = malloc(sizeof(int) * N);
	if (!board)
	{
		fprintf(stderr, "malloc failed\n");
		return (1);
	}
	solveNQueens(0);
	free(board);
	return (0);
}
