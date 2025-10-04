
#include <unistd.h>

int	is_white_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_valid(char c, int str_base)
{
	char	*lower_base = "0123456789abcdef";
	char	*upper_base = "0123456789ABCDEF";
	int		i = 0;

	while(i < str_base)
	{
		if (c == lower_base[i] || c == upper_base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	sign = 1;
	int result = 0;

	while (is_white_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && is_valid(str[i], str_base))
	{
		result *= str_base;
		
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - 'A' + 10;
		i++;
	}
	return (result * sign);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3 || av[1][0] == '\0' || av[2][0] == '\0')
		return (write(1, "\n", 1), 1);
	
	int	str_base = atoi(av[2]);
	char *str = av[1];
	long int	result = 0;

	result = (long int)ft_atoi_base(str, str_base);
	printf("own = %ld\n", result);
	result = strtol(str, NULL, str_base);
	printf("strtol = %ld\n", result);
	return (0);
}
