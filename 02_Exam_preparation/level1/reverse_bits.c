

unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 7;
	unsigned char	result = 0;

	while (i >= 0)
	{
		result = (result << 1) | (octet & 1);
		octet = octet >> 1;
		i--;
	}
	return (result);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf("wrong number of arguments\n"), 1);
	int byte;
	unsigned char octet;
	unsigned char result;
	byte = atoi(av[1]);
	if (byte > 255 || byte < 0)
		return (printf("invalid input\n"), 1);
	octet = (unsigned char)byte;
	print_bits(octet);
	write (1, "\n", 1);
	result = reverse_bits(octet);
	print_bits(result);
	write (1, "\n", 1);
	return (0);
}
