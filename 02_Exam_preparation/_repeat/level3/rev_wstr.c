
#include <unistd.h>
#include <stdlib.h>

int	main (int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 1);
	char	*str = av[1];
	int	i = 0;
	int start = 0;
	int	end = 0;

	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		end = i;
		while(i >= 0 && str[i] != ' ')
			i--;
		start = i + 1;
		while (start <= end)
		{
			write(1, &str[i], 1);
			start++;
		}
		if (i > 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}
