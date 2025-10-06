
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf("\n"), 1);

	unsigned int n = atoi(av[1]);
	unsigned int i = 2;

	if (n == 1)
		printf("1");

	while (n >= i)
	{
		if (n % i == 0)
		{
			printf("%d", i);
			if (n != i)
				printf("*");
			n = n / i;
		}
		else
			i++;
	}
	printf("\n");
	return (0);	
}
