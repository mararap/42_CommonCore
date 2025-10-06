
#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	ft_cptlzr(char *str)
{
	int		i = 0;
	char	c = '\0';

	while (str[i])
	{
		c = str[i];
		if (str[i] >= 'A' && str[i] <= 'Z')
			c = str[i] + 32;
		if ((str[i] >= 'a' && str[i] <= 'Z') &&
			ft_isspace(str[i + 1]))
			c = str[i] - 32;
		write (1, &c, 1);
		i++;
	}
}

int main (int ac, char **av)
{
	if (ac == 1)
		return(write(1, "\n", 1), 1);

	int i = 1;

	while (i < ac)
	{
		ft_cptlzr(av[i]);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
