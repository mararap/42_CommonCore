/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azielnic <azielnic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:39:56 by azielnic          #+#    #+#             */
/*   Updated: 2025/12/08 22:54:38 by azielnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_safe(int *board, int col, int row)
{
	int	c = 0;
	int	r;
	
	while (c < col)
    {
        r = board[c];
        if (r == row)
            return (0);
        if ((r - c) == (row - col))
            return (0);
        if ((r + c) == (row + col))
            return (0);
		c++;
    }
    return (1);
}

void print_solution(int *board, int n)
{
    int	i = 0;

	while (i < n)
	{
		fprintf(stdout, "%i", board[i]);
        if (i + 1 < n)
            fprintf(stdout, " ");
		i++;
	}	
    fprintf(stdout, "\n");
}

void solve(int *board, int col, int n)
{
	int row = 0;
	
	if (col == n)
    {
        print_solution(board, n);
        return ;
    }
    while (row < n)
	{
		if (is_safe(board, col, row))
		{
	        board[col] = row;
            solve(board, col + 1, n);		
		}
		row++;
	}
}

int main(int argc, char **argv)
{
	int *board;
	int n;
	
	if (argc != 2)
        return (1);
    n = atoi(argv[1]);
    if (n <= 0)
        return (0);
    board = malloc(sizeof(int) * n);
    if (!board)
        return (1);
    solve(board, 0, n);
    free(board);
    return (0);
}
