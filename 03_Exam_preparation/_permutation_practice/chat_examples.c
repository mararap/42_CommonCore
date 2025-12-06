
#include <stdio.h>
#include <string.h>

void	subsets(char *str, int i, char *buf, int j)
{
	if ((unsigned long)i == strlen(str))
	{
		buf[j] = '\0';
		printf("%s\n", buf);
		return ;
	}
	buf[j] = str[i];
	subsets(str, i + 1, buf, j + 1);
	subsets(str, i + 1, buf, j);
	return ;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char	buf[100];

	subsets(av[1], 0, buf, 0);
	return (0);
}
