
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 7;
	char num;

	while (i >= 0)
	{
		num = ((octet >> i) & 1) + 48;
		write (1, &num, 1);
		i--;
	}
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf("wrong number of arguments\n"), 1);
	int num;
	unsigned char octet;	
	num = atoi(av[1]);
	if (num > 255 || num < 0)
		return (printf("invalid input\n"), 1);
	octet = (unsigned char)num;
	print_bits(octet);
	return (0);
}