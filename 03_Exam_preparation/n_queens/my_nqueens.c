
#include <stdlib.h>
#include <stdio.h>

int	*g_solution;
int	g_n;

void	print_solution()
{
	int i;

	i = 0;
	while (i < g_n)
	{
		fprintf(stdout, "%d", g_solution[i]);
		if (i + 1 < g_n)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int	is_safe(int x, int y)
{
	int x_temp = 0;	
	int value = 0;
	
	while (x_temp < x)		// for every column-index until we reach the current(?)
	{
		value = g_solution[x_temp];     // value = value of solution[0], [1], [2] ...
		if (value == y)
			return (0);
		if ((value - x_temp) == (y - x))
			return (0);
		if ((value + x_temp) == (y + x))
			return (0);
		x_temp++;
	}
	return (1);
}

void	solve(int x)    // function called with 0
{				    	// therefor first line-idx = 0
	int y = 0; 
	
	if (x == g_n)	// once we reach the final column-idx
	{
		print_solution(); 	// call print function
		return ;
	}
	while (y < g_n)		// until we reach last line-idx
    {	
		if (is_safe(x, y))		// if is_save returns 1
		{					    // aka position at row-idx X col-idx is save,
			g_solution[x] = y;	// fill current row-position with value of col@col-idx?
			solve(x + 1);		// call solve-function recursivly for x + 1
		}					    // next row as long as is_save keeps
		y++;   					// returning 1
	}
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1][0]) 			// check args
		return (1);
	g_n = atoi(av[1]);					// set number of queens/rows/columns to av[1]
	if (g_n < 0) 
		return (0);
	g_solution = malloc(sizeof(int) * g_n);	// allocate for int *solution
	if (!g_solution)
		return (1);
	solve(0);							// call function
	free(g_solution);						// free
	return (0);							// return
}
