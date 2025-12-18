
#include "my_nqueens.h"

int	*g_solution;
int	g_n;

static void	print_solution(void)
{
	int i = 0;

	while (i < g_n)
	{
		printf("%d", g_solution[i]);
		if (i + 1 < g_n)
			printf(" ");
		i++;
	}
	printf("\n");
}

static int	is_safe(int x, int y)
{
	int x_temp = 0;	
	int value = 0;
	
	while (x_temp < x)					// for every column-index until we reach the current
	{
		value = g_solution[x_temp];
		if (value == y)					// if there is a queen in the same horizontal line
			return (0);
		if ((value - x_temp) == (y - x))// if there is a queen in one diagonal line
			return (0);
		if ((value + x_temp) == (y + x))// if there is a queen in the other diagonal line
			return (0);
		x_temp++;
	}
	return (1);
}

void	find_solutions(int x)
{
	int y = 0; 
	
	if (x == g_n)					// once we reach the final column-idx
	{
		print_solution();			// call print function
		return ;
	}
	while (y < g_n)					// until we reach last line-idx
    {	
		if (is_safe(x, y))
		{
			g_solution[x] = y;
			find_solutions(x + 1);	//proceed with next column
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
		return (1);
	g_n = atoi(av[1]);
	if (g_n < 0) 
		return (0);
	g_solution = malloc(sizeof(int) * g_n);
	if (!g_solution)
		return (1);
	find_solutions(0);
	free(g_solution);
	return (0);
}
