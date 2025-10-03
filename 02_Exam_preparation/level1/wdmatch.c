
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1), 1);

	int	i = 0;
	int	j = 0;
	int	len = 0;
	char *s1 = av[1];
	char *s2 = av[2];

	while(s1[len])
		len++;
	while(s2[j] && s1[i])
	{
		if (s1[i] == s2[j])
			i++;
		j++;
	}
	if (i == len)
		write(1, s1, len);
	write (1, "\n", 1);
	return (0);	
}