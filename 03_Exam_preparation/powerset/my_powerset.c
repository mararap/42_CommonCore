#include <stdlib.h>
#include <stdio.h>

static int *g_num;
static int g_n;

void	search(int idx, int target_sum, int current_sum, int subset[], int subset_size)
{
	int	i = 0;
	if (idx == g_n)
	{
		if (current_sum == target_sum)
		{
			while (i < subset_size)
			{
				printf("%d ", subset[i]);
				i++;
			}
			printf("\n");
		}
		return ;
	}
	search(idx + 1, target_sum, current_sum, subset, subset_size);
	subset[subset_size] = g_num[idx];
	search(idx + 1, target_sum, current_sum + g_num[idx], subset, subset_size + 1);
}

int	main(int ac, char **av)
{
	int	*input_set;
	int	target_sum;
	int	subset[100];
	int i = 2;
	int j = 0;
	// allocate memory for array of int "input_set"
	input_set = malloc((ac - 2) * sizeof(int));
	if (!input_set)
		return(1);
	// write input set of int (atoi(char)) into array "input_set"
	while (i < ac)
	{
		input_set[j] = atoi(av[i]);
		j++;
		i++;
	}
	g_num = input_set;
	g_n = ac - 2;
	target_sum = atoi(av[1]);
	search(0, target_sum, 0, subset, 0);
	free(input_set);
	return (0);
}

