
unsigned int	ft_gcd(unsigned int a, unsigned int b)
{
	unsigned int	temp = 0;

	while (b != 0)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	result = 0;
	if (a == 0 || b == 0)
		return (0);
	result = (a / ft_gcd(a, b)) * b;
	return (result);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char** av)
{
	if (ac != 3)
		return (printf("wrong number of arguments\n"), 1);
	unsigned int	a = (unsigned int) atoi(av[1]);
	unsigned int	b = (unsigned int) atoi(av[2]);
	unsigned int	result = 0;
	unsigned int	gcd = 0;
	gcd = ft_gcd(a, b);
	printf("gcd = %d\n", gcd);
	result = lcm(a, b);
	printf("lcm = %d\n", result);
	return (0);
}
