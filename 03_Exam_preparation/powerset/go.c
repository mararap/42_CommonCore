
#include <stdlib.h>
#include <stdio.h>

static int *g_set;
static int g_len;

void	find_subsets(int idx, int target_sum, int current_sum,
				int subset[], int subset_len)
{
	int	i = 0;
	if (current_sum > target_sum)
		return ;
	if (idx == g_len)
	{
		if (current_sum == target_sum)
		{
			while (i < subset_len)
			{
				printf("%d", subset[i]);
				if ((i + 1) < subset_len)
					printf(" ");
				i++;
			}
			printf("\n");
		}
		return ;
	}
	find_subsets(idx + 1, target_sum, current_sum,
			subset, subset_len);
	subset[subset_len] = g_set[idx];
	find_subsets(idx + 1, target_sum, current_sum + g_set[idx],
			subset, subset_len + 1);
}

int	main(int ac, char **av)
{
	int	*input_set;
	int	target_sum;
	int	subset[100];
	int i = 2;
	int j = 0;

	input_set = malloc((ac - 2) * sizeof(int));
	if (!input_set)
		return(1);
	while (i < ac)
	{
		input_set[j] = atoi(av[i]);
		j++;
		i++;
	}
	g_set = input_set;
	g_len = ac - 2;
	target_sum = atoi(av[1]);
	find_subset(0, target_sum, 0, subset, 0);
	free(input_set);
	return (0);
}

