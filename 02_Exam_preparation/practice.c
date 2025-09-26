
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result = 0;
	int				i = 0;
	
	while(i < 8)
	{
	result = (result << 1) | (octet & 1);
	octet = (octet >> 1);
	i++;
	}
	return (result);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf("wrong number of arguments\n"), 1);
	int num = atoi(av[1]);
	if (num > 255 || num < 0)
		return (printf("invalid input\n"), 1);
	int	i = 7;
	char	output = 0;
	unsigned char input = (unsigned char)num;
	printf("num = %d\n", num);
	printf("input = %d\n", input);
	output = reverse_bits(input);
	printf("output = %d\n", output);
	while (i >= 0)
	{
		output = ((output >> i) & 1);
		printf("%d", output);
		i--;	
	}
	return (0);
}
