
#include <stdio.h>
#include <stdlib.h>

int	*solution;
int	N;
/*
unsigned int	my_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}*/

void	print_solution()
{
	int i;

	i = 0;
	while (i < N)
	{
		fprintf(stdout, "%d", solution[i]);
		if (i + 1 < N)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int	is_safe(int x, int y)
{
	int x_temp = 0;	
	int value = 0;
	
	while (x_temp < x)	// for every column-index until we reach the current(?)
	{
		value = solution[x_temp];	// value = value of solution[0], [1], [2] ...
		if (value == y)
			return (0);
		if ((value - x_temp) == (y - x))
			return (0);
		if ((value + x_temp) == (y + x))
			return (0);
//		if (my_abs(x_temp - x) == my_abs(y_temp - y))
//			return (0);
		x_temp++;
	}
	return (1);
}

void	solve(int x) 				// function called with 0
{									// therefor first line-idx = 0
	int y = 0; 
	
	if (x == N)						// once we reach the final line-idx
	{
		if (N < 4)
			fprintf(stdout, "\n");
		else
			print_solution();			// we call print function
		return ;
	}
	while (y < N)					// until we reach last col-idx
	{
		if (is_safe(x, y))			// if is_save returns 1
		{							// aka position at row-idx X col-idx is save,
			solution[x] = y;		// fill current row-position with value of col@col-idx?
			solve(x + 1);			// call solve-function recursivly for
		}							// next row as long as is_save keeps
		y++;						// returning 1
	}
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[0][1]) 			// check args
		return (1);
	N = atoi(av[1]);					// set number of queens/rows/columns to av[1]
	if (N < 0) 
		return (0);
	if (N < 4)
		return (fprintf(stdout, "\n"), 0);
	solution = malloc(sizeof(int) * N);	// allocate for int *solution
	if (!solution)
		return (1);
	solve(0);							// call function
	free(solution);						// free
	return (0);							// return
}
