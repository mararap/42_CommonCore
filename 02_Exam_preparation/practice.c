
#include <unistd.h>

void	ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	write (1, &"0123456789"[num % 10], 1);
}

int	main()
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
			write (1, "fizz", 5);
		if (i % 5 == 0)
			write (1, "buzz", 5);
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "fizzbuzz", 9);
		else
			ft_putnbr(i);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
