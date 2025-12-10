#include <stdio.h>
#include <stdlib.h>

int	pass_check(char **av)
{
	int i = 1;
	int j;

	while(av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_subset(int *subset, int index)
{
	int i = 0;

	while (i < index)
	{
		printf("%d", subset[i]);
		if (i + 1 != index)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	find_subset(int target, int size, int *set, int *subset, int index, int pos, int sum)
{
	if (pos == size)
	{
		if (sum == target)
			print_subset(subset, index);
		return ;
	}
	subset[index] = set[pos];
	find_subset(target, size, set, subset, index + 1, pos + 1, sum + set[pos]);
	find_subset(target, size, set, subset, index, pos + 1, sum);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (!pass_check(av))
		return (0);
	int target = atoi(av[1]);
	int size = ac - 2;
	if (size <= 0)
	{
		if (target == 0)
			printf("\n");
		return (0);
	}
	int *set = malloc(sizeof(int) * size);
	if (!set)
		return (1);
	int *subset = malloc(sizeof(int) * size);
	if (!subset)
		return (free(set), 1);
	int i = 0;
	while (i < size)
	{
		set[i] = atoi(av[i + 2]);
		i++;
	}
	find_subset(target, size, set, subset, 0, 0, 0);
	free(set);
	free(subset);
	return (0);

}
