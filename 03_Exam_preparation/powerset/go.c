
#include <stdio.h>
#include <stdlib.h>

static int *g_set;
static int	g_len;

void	search(int idx, int target_sum,int current_sum,
				int subset[], int subset_size)
{
	int i = 0;
	if (current_sum > target_sum)
		return ;


int	main(int ac, char **av)
{
	int	*input_set;
	int	target_sum;
	int	subset[100];
	int	i = 2;
	int	j = 0;

	input_set = malloc((ac - 2) * sizeof(int));
	if (!input_set)
		return (1);
	while (1 < ac)
	{
		input_set[j] = atoi(av[i]);
		j++;
		i++;
	}
	g_set = input_set;
	g_len = ac - 2;
	target_sum = atoi(av[1]);
	search(0, target_sum, 0, subset, 0);
	free(input_set);
	return (0);
}
