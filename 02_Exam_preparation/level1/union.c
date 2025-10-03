
#include <unistd.h>

int	no_doub(char *str, char c, int i)
{
	i--;
	while(i >= 0)
	{
		if (str[i] == c)
			return (1);
		i--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return(write(1, "\n", 1), 1);

	int	i = 0;
	int j = 0;
	char *s1 = av[1];
	char *s2 = av[2];

	while (s1[i])
	{
		if (no_doub(s1, s1[i], i) == 0)
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (no_doub(s2, s2[j], j) == 0 && no_doub(s1, s2[j], i) == 0)
			write(1, &s2[j], 1);
		j++;
	}
	write (1, "\n", 1);
	return (0);
}