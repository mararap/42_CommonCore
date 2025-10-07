
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		len = 1;
	int		sign = 1;
	int		tmp = nbr;
	char 	*arr;
	long	n = nbr;

	if (n == 0)
	{
		arr = malloc(2);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	if (n < 0)
	{
		len++;
		sign = -1;
		n *= -1;
	}
	while (tmp / 10 != 0)
	{
		tmp /= 10;
		len++;
	}
	arr = malloc(len + 1);
	arr[len] = '\0';
	while (n > 0)
	{
		len--;
		arr[len] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		arr[0] = '-';
	return (arr);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;

	int nbr = atoi(av[1]);
	printf("int = %d\n", nbr);
	char *arr = ft_itoa(nbr);
	printf("arr = %s\n", arr);
	return (0);
}
