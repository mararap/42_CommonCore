
#include <stdio.h>
#include <stdlib.h>

static int	is_valid(const char *str)
{
	int balance = 0;
	
	for(int i = 0; str[i]; i++)
	{
		if (str[i] == '(')
			balance++;
		else if (str[i] == ')')
		{
			if (balance == 0)
				return (0);
			balance--;
		}
	}
	return (balance == 0);
}

void	permute(char *str, int i, int rem_l, int rem_r, int open)
{
	if (!str[i])
	{
		if (rem_l == 0 && rem_r == 0 && is_valid(str))
			puts(str);
		return ;
	}
	char c = str[i];
	if (c == '(' && rem_l > 0)
	{
		char save = str[i];
		str[i] = ' ';
		permute(str, i + 1, rem_l - 1, rem_r, open);
		str[i] = save;
	}
	if (c == ')' && rem_r > 0)
	{
		char save = str[i];
		str[i] = ' ';
		permute(str, i + 1, rem_l, rem_r - 1, open);
		str[i] = save;
	}
	if (c == '(')
		permute(str, i + 1, rem_l, rem_r, open + 1);
	else if (c == ')')
	{
		if (open > 0)
			permute(str, i + 1, rem_l, rem_r, open - 1);
	}
	else
		permute(str, i + 1, rem_l, rem_r, open);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int l = 0, r = 0;
	int open = 0;
	for (int i = 0; av[1][i]; i++)
	{
		if (av[1][i] == '(')
			open++;
		else if (av[1][i] == ')')
		{
			if (open == 0)
				r++;
			else
				open--;
		}
	}
	l = open;
	permute(av[1], 0, l, r, 0);
	return (0);
}


