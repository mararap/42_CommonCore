
#include <stdio.h>
#include <stdlib.h>

void	swap(char *a, char *b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	permute(char *str, int left)
{
	if (!str[left])
	{
		puts(str);
		return ;
	}
	for (int i = left; str[i]; i++)
	{
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
	permute(av[1], 0);
	return(0);
}
