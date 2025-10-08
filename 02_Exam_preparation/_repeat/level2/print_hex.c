
#include <unistd.h>

int	ft_atoi(char *str)
{
	unsigned int result = 0;
	unsigned int i = 0;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}
void	ft_puthex(unsigned int nbr)
{
	char	*hex_base = "0123456789abcdef";

	if (nbr >= 16)
		ft_puthex(nbr / 16);
	nbr = hex_base[nbr % 16];
	write (1, &nbr, 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 1);

	unsigned int	nbr = (unsigned int)ft_atoi(av[1]);
	if (!nbr || nbr > 4294967295)
		return (write(1, "\n", 1), 1);
	ft_puthex(nbr);
	write (1, "\n", 1);
	return (0);
}
