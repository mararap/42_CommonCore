
#include <stdio.h>
#include <stdlib.h>

static int	*g_set;
static int	g_len;

void	search(int idx, int target_sum, int current_sum, int subset[], int subset_size)
{
	int i = 0;
	if (idx == g_len)
	{
		if (current_sum == target_sum)
		{
			while(i < subset_size)
			{
				printf("%d ", subset[i]);
				i++;
			}
			printf("\n");
		}
		return ;
	}
	search (idx + 1, target_sum, current_sum, subset, subset_size);
	subset[subset_size] = g_set[idx];
	search (idx + 1, target_sum, current_sum + g_set[idx], subset, subset_size + 1);
}

int	main(int ac, char **av)
{
	int	 *input_set;
	int	target_sum;
	int subset[100];
	int	i = 2;
	int j = 0;

	input_set = malloc((ac - 2) * sizeof(int));
	if (!input_set)
		return (0);
	while (i < ac)
	{
		input_set[j] = atoi(av[i]);
		i++;
		j++;
	}
	g_set = input_set;
	g_len = ac - 2;
	target_sum = atoi(av[1]);
	search(0, target_sum, 0, subset, 0);
	free(input_set);
	return (0);
}
