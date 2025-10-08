
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (printf("\n"), 1);

	unsigned int	a;
	unsigned int	b;
	unsigned int	temp;

	a = (unsigned int)atoi(av[1]);
	b = (unsigned int)atoi(av[2]);

	while (b != 0)
	{
		temp = b;
		b = a % temp;
		a = temp;
	}
	printf("%d\n", a);
	return (0);
}
