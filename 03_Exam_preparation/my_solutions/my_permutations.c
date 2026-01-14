
#include "my_permutations.h"

static void	swap(char *a, char *b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort(char *str)
{
	int	i = 0;
	int j;

	while(str[i + 1])
	{
		j = 0;
		while (str[j + 1])
		{
			if (str[j] > str[j + 1])
				swap(&str[j], &str[j + 1]);
			j++;
		}
		i++;
	}
}

static int	next_min(char *str, int left, char last)
{
	int	i;
	int min = -1;

	for (i = left; str[i]; i++)
	{
		if (str[i] > last && (min == -1 || str[i] < str[min]))
			min = i;
	}
	return (min);
}

void	permute(char *str, int left)
{
	int		i;
	char	last;

	if (!str[left])
	{
		puts(str);
		return ;
	}
	last = 0;
	while ((i = next_min(str, left, last)) != -1)
	{
		last = str[i];
		swap(&str[left], &str[i]);
		permute(str, left + 1);
		swap(&str[left], &str[i]);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1] == NULL || !av[1][0])
		return (1);
	(void)ac;
	sort(av[1]);
	permute(av[1], 0);
	return(0);
}
