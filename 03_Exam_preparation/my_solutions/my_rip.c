
#include "my_rip.h" 

void	permute(char *str, int i, int rem_l, int rem_r, int open)
{
	if (!str[i])
	{
		if (rem_l == 0 && rem_r == 0 && open == 0)
			puts(str);
		return ;
	}
	if (str[i] == '(')
	{
		if (rem_l > 0)
		{
			str[i] = ' ';
			permute(str, i + 1, rem_l - 1, rem_r, open);
			str[i] = '(';
		}
		permute(str, i + 1, rem_l, rem_r, open + 1);
	}
	else if (str[i] == ')')
	{
		if (rem_r > 0)
		{
			str[i] = ' ';
			permute(str, i + 1, rem_l, rem_r - 1, open);
			str[i] = ')';
		}
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
	int rem_l = 0, rem_r = 0;
	int open = 0;
	for (int i = 0; av[1][i]; i++)
	{
		if (av[1][i] == '(')
			open++;
		else if (av[1][i] == ')')
		{
			if (open == 0)
				rem_r++;
			else
				open--;
		}
	}
	rem_l = open;
	permute(av[1], 0, rem_l, rem_r, 0);
	return (0);
}
