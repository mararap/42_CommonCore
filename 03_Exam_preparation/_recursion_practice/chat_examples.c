
#include <stdio.h>
#include <stdlib.h>

void	end_to_start(int start, int end)
{
	if (start > end)
		return ;
	printf("%d", end);
	if (end > start)
		printf(" ");
	else if (end == start)
	{
		printf("\n");
		return ;
	}
	end_to_start(start, end - 1);
}

void	start_to_end(int start, int end)
{
	if (start > end)
	{
		printf("\n");
		return ;
	}
	printf("%d ", start);
	start_to_end(start + 1, end);
}

int	main(int ac, char **av)
{
	int	start;
	int	end;

	if (ac != 3)
		return (1);
	start = atoi(av[1]);
	end = atoi(av[2]);
	start_to_end(start, end);
	end_to_start(start, end);
	return (0);
}
