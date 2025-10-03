
int	is_power_of_2(unsigned int n)
{
	if (n % 2 == 0)
	{
		if (n == 0 || n == 2)
			return (0);
		return (1);
	}
	return (0);
}

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	unsigned int	num = 0;
	int				result = 0;

	num = (unsigned int)atoi(av[1]);
	result = is_power_of_2(num);
	printf("result = %d\n", result);
	return (0);
}
