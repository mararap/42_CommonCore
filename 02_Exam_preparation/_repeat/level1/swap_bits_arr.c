
unsigned char	reverse_bits(unsigned char octet)
{
	int	arr_ori[8];
	int	arr_rev[8];
	int	i = 7;
	int	j = 0;
	int	factor = 1;
	int	result = 0;
	while (i >= 0)
	{
		arr_ori[i] = octet % 2;
		octet = octet / 2;
		i--;
	}
	i = 7;
	while (i >= 0)
	{
		arr_rev[j] = arr_ori[i];
		i--;
		j++;
	}
	i = 7;
	while (i >= 0)
	{
		result += (arr_rev[i] * factor);
		i--;
		factor *= 2;
	}
	return (result);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return(printf("wrong number of arguments\n"), 1);
	unsigned char	octet = (unsigned char)atoi(av[1]);
	unsigned char	bit = 0;
	unsigned char	res = reverse_bits(octet);

	int i = 7;
	printf("ori_bin = ");
	while (i >= 0)
	{
		bit = (octet >> i & 1) + 48;
		printf("%c", bit);
		i--;
		
	}
	printf("\nrev_bin = ");
	i = 7;
	bit = 0;

	while (i >= 0)
	{
		bit = (res >> i & 1) + 48;
		printf("%c", bit);
		i--;
	}
	printf("\n");
	return (0);
}
