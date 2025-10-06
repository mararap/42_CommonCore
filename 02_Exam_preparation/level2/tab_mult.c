
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i = 0;
	int result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

void ft_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr	% 10 + '0';
	write (1, &c, 1);
}

int	main (int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 1);

	int nbr = ft_atoi(av[1]);
	int i = 1;
	int	result = 0;

	while (i <= 9)
	{
		result = i * nbr;
		ft_putnbr(i);
		write (1, " x ", 3);
		ft_putnbr(nbr);
		write (1, " = ", 3);
		ft_putnbr(result);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
