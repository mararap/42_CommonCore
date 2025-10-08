
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return(write(1, "\n", 1), 1);

	char *s1 = av[1];
	char *s2 = av[2];
	int	i = 0;
	int j = 0;

	if (s1[i] == '\0')
		return(write(1, "1\n", 2), 0);
	while (s1[i] && s2[j])
	{
		if (s2[j] == s1[i])
			i++;
		j++;
	}
	if (s1[i] == '\0')
		write (1, "1\n", 2);
	else (write(1, "0\n", 2));
	return (0);
}
