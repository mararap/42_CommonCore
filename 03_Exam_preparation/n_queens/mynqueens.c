
#include <stdio.h>
#include <stdlib.h>

int	*solution;
int	N;

int	is_safe(int y, int x)
{
	int i = 0;
	int prev_col;
	
	while (i < y)	// until we reach the last row
	{
		prev_col = solution[i];	// 
		if (prev_col == x)
			return (0);
		if (abs(prev_col - x) == abs(i - y))
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
			if (solution[i] == j)
				printf("%d", j);
			j++;
		}
		i++;
	}
	printf("\n");
}

void	solve_n_queens(int y) 		// function called with 0
{									// therefor row-idx = 0
	int x; 
	
	if (y == N)						// once we reach the final row-idx
	{
		print_solution();			// we call print function
		return ;
	}
	x = 0;
	while (x < N)					// until we reach last col-idx
	{
		if (is_safe(y, x))			// if is_save returns 1
		{							// aka position at row-idx X col-idx is save,
			solution[y] = x;		// fill current row-position with value of col@col-idx?
			solve_n_queens(y + 1);	// call solve-function recursivly for
		}							// next row as long as is_save keeps
		x++;						// returning 1
	}
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[0][1]) // check number of args
		return (1);
	N = atoi(av[1]);	// set number of queens/rows/columns to av[1]
	if (N < 1) 
	{
		fprintf(stderr, "Invalid input\n"); // invalid input 
		return (0);
	}
	solution = malloc(sizeof(int) * N);	// allocate for int *solution
	if (!solution)
	{
		fprintf(stderr, "malloc failed\n"); // malloc-check
		return (1);
	}
	solve_n_queens(0);	// call function
	free(solution);		// free
	return (0);			// return
}
