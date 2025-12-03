
#include <stdio.h>
#include <stdlib.h>

int	*board;
int	N;

int	is_safe(int row, int col)
{
	int i = 0;
	int prev_col;
	
	while (i < row)	// until we reach the last row
	{
		prev_col = board[i];	// 
		if (prev_col == col)
			return (0);
		if (abs(prev_col - col) == abs(i - row))
			return (0);
		i++;
	}
	return (1);
}

void	print_solution()
{
	int i;
	int j;

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

void	solve_n_queens(int row) // function called with 0
{								// therefor row = 0
	int col;
	
	if (row == N)				// once we reach the final row
	{
		print_solution();		// we call print function
		return ;
	}
	col = 0;
	while (col < N)				// until we reach last column
	{
		if (is_safe(row, col))	// if is_save returns 1
		{						// aka position at row X col is save,
			board[row] = col;	// fill current row-position with value of col?
			solve_n_queens(row + 1);	// call solve-function recursivly for
		}								// next row as long as is_save keeps
		col++;							// returning 1
	}
}

int	main(int ac, char **av)
{
	if (ac != 2) // check number of args
	{
		fprintf(stderr, "Usage: %s <N>\n", argv[0]);
		return (1);
	}
	N = atoi(argv[1]);	// set global variable to av[1]
	if (N < 1)			// = number of queens/rows/columns
	{
		fprintf(stderr, "Invalid N\n"); // check validity
		return (0);
	}
	board = malloc(sizeof(int) * N);	// allocate for "board"
	if (!board)							// aka temp. array
	{
		fprintf(stderr, "malloc failed\n"); // malloc-check
		return (1);
	}
	solve_n_queens(0);	// call function
	free(board);		// free
	return (0);			// return
}
