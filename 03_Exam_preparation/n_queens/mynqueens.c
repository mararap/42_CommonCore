
#include <stdio.h>
#include <stdlib.h>

int	*solution;
int	N;

unsigned int	myabs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	is_safe(int x, int y)
{
	int y_temp = 0;		// was i
	int x_temp = 0;			// was prev_col
	
	while (x_temp < x)	// for every line until we reach the current(?)
	{
		y_temp = solution[x_temp];	// 
		if (y_temp == y)
			return (0);
		if ((y_temp - x_temp) == (y - x))
//		if (myabs(x_temp - x) == myabs(y_temp - y))
//			return (0);
		x_temp++;
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
{									// therefor first line-idx = 0
	int x = 0; 
	
	if (y == N)						// once we reach the final line-idx
	{
		print_solution();			// we call print function
		return ;
	}
	while (x < N)					// until we reach last col-idx
	{
		if (is_safe(x, y))			// if is_save returns 1
		{							// aka position at row-idx X col-idx is save,
			solution[x] = y;		// fill current row-position with value of col@col-idx?
			solve_n_queens(x + 1);	// call solve-function recursivly for
		}							// next row as long as is_save keeps
		x++;						// returning 1
	}
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[0][1]) // check args
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
