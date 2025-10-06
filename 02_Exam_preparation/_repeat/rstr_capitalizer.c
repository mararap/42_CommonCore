
#include <unistd.h>

int	white_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_alpha_up(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_alpha_lo(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (write(1, "\n", 1), 1);

	int	i = 1;
	int	j = 0;
	char	c = '\0';

	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (white_space(av[i][j]))
				j++;
			c = av[i][j];
			if (is_alpha_up(av[i][j]) || is_alpha_lo(av[i][j]))
			{
				if(white_space(av[i][j + 1]) || av[i][j + 1] == '\0')
				{
					if (is_alpha_lo(av[i][j]))
						c = av[i][j] - 32;
				}
				else if (is_alpha_up(av[i][j]))
					c = av[i][j] + 32;
			}
			write(1, &c, 1);
			if (white_space(av[i][j + 1]))
				write(1, " ", 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
