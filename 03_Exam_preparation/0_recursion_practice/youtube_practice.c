// https://www.youtube.com/watch?v=ngCos392W4w&t=2s

#include <stdlib.h>
#include <stdio.h>

int	grid_paths(int n, int m)
{
	if (n == 1 || m == 1)
		return (1);
	else
		return (grid_paths(n, m -1) + grid_paths (n - 1, m));
}

int	count_partition(int n, int m)
{
	if (n == 0)
		return (1);
	else if (m == 0 || n < 0)
		return (0);
	else
		return (count_partition(n - m, m) + count_partition(n, m - 1));
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	int	n = atoi(av[1]);
	int m = atoi(av[2]);
	int grids = grid_paths(n, m);
	printf("grid paths count = %d\n", grids);
	int part_count = count_partition(n, m);
	printf("partitions count = %d\n", part_count);
	return (0);
}
