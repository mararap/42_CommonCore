
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 1);
	
	int		i = 0;
	char 	*str = av[1];

	while(str[i])
	{
		if (str[i] == '_')
		{
			i++;
			str[i] = str[i] - 32;
		}
		write(1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}
