#include <stdlib.h>
#include <unistd.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	pass_check(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_swap(char *a, char *b)
{
	char	tmp = *a;

	*a = *b;
	*b = tmp;
}

void	sort_string(char *str, int i)
{
	int j;

	while(str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				ft_swap(&str[i], & str[j]);
			j++;
		}
		i++;
	}
}

void	permutate(char *str, int start)
{
	if (!str[start])
	{
		int len = 0;
		while (str[len])
			len++;
		write(1, str, len);
		write(1, "\n", 1);
		return ;
	}
	int i = start;
	while (str[i])
	{
		ft_swap(&str[i], &str[start]);
		sort_string(str, start + 1);
		permutate(str, start + 1);
		ft_swap(&str[i], &str[start]);
		i++;
	}
}


int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if(!pass_check(av[1]))
		return (0);
	sort_string(av[1], 0);
	permutate(av[1], 0);
	return (0);
}
