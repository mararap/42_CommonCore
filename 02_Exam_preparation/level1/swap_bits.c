
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 7;
	char c;

	while (i >= 0)
	{
		c = ((octet >> i) & 1) + 48;
		write (1, &c, 1);
		i--;
	}
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
	result = swap_bits(octet);
	print_bits(result);
	write (1, "\n", 1);
	return (0);
}