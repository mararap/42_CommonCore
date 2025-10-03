
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i = 0;
	int sign = 1;
	int	num = 0;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while(str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
void	ft_putnbr(int i)
{
	char	c;

	if (i < 0)
	{
		write (1, "-", 1);
		i *= -1;
	}
	if (i >= 10)
		ft_putnbr(i / 10);
	c = i % 10 + '0';
	write (1, &c, 1);
}
int	ft_is_prime(int num)
{
	if (num == 1)
		return (1);
	else if (num == 0)
		return (0);
	int	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}
int	main(int ac, char **av)
{
	if (ac != 2)
		return (write (1, "\n", 1), 1);

	int	num = ft_atoi(av[1]);
	int	result = 0;

	if (num < 0)
		return (write(1, "\n", 1));

	while(num > 1)
	{
		if (ft_is_prime(num))
			result += num;
		num--;
	}
	ft_putnbr (result);
	write (1, "\n", 1);
	return (0);
}