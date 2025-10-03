
#include <unistd.h>

int	main(int ac, char **av)
{
	int i = 0;
	int end;
	char *str = av[1];

	if(ac != 2)
		return(write(1, "\n", 1));
	while(str[i])
		i++;
	i--;
	while (str[i] == 32 || str[i] == 9)
		i--;
	end = i;
	while(i >= 0 && !(str[i] == 32 || str[i] == 9))
		i--;
	i++;
	while(str[i] && i <= end)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}