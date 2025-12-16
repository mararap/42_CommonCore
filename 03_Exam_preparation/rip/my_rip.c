
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_balanced(char *str, int len)
{
	int balance = 0;
	int i = 0;

	while (i < len)
	{
		if(str[i] == '(')
			balance++;
		else if (str[i] == ')')
		{
			balance--;
			if (balance < 0)
				return (0);
		}
		i++;
	}
	return (balance == 0);
}

void	backtrack(char *str, int *min_removals, int idx, int current_removals, int mode)
{
	if (mode == 0 && current_removals > *min_removals)
		return ;
	if (is_balanced(str, ft_strlen(str)))
	{
		if (mode == 0)
		{
			if (current_removals < *min_removals)
				*min_removals = current_removals;
		}
		else if (mode == 1 && current_removals == *min_removals)
		{
			write (1, str, ft_strlen(str));
			write (1, "\n", 1);
		}
		return ;
	}
	int	i = idx;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == ')')
		{
			char	saved = str[i];
			str[i] = ' ';
			backtrack(str, min_removals, i + 1, current_removals + 1, mode);
			str[i] = saved;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	// check args
	if (ac != 2 || !av[1][0])
		return (1);
	int	i = 0;
	// check input (only brackets and spaces)
	while(av[1][i])
	{
		if(av[1][i] != '(' && av[1][i] != ')' && av[1][i] != ' ')
			return (1);
		i++;
	}
	int	min_removals = ft_strlen(av[1]);
	// find min
	backtrack(av[1], &min_removals, 0, 0, 0);
	// print solutions
	backtrack(av[1], &min_removals, 0, 0, 1);
	return (0);
}
