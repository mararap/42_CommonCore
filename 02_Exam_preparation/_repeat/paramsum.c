
#include <unistd.h>

void ft_putnbr(int num)
{
	char c;

	if (num > 9)
		ft_putnbr(num / 10);
	c = num % 10 + '0';
	write (1, &c, 1);
}

int	main(int ac, char **av)
{
	(void) av;

	if (ac == 1)
		return(write (1, "\n", 1), 0);
	ft_putnbr(ac - 1);
	write (1, "\n", 1);
	return (0);
}
