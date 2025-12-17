
#include <unistd.h>
#include <stdio.h>

static int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

static int	is_valid(const char *s)
{
	int	bal = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(') bal++;
		else if (s[i] == ')')
		{
			if (bal == 0)
				return (0);
			bal--;
		}
	}
	return (bal == 0);
}

void	permute(char *s, int i, int remL, int remR, int open)
{
	if (!s[i])
	{
		if (remL == 0 && remR == 0 && open == 0 && is_valid(s))
			ft_putstr(s);
		return;
	}
	char c = s[i];
	//remove current '('
	if (c == '(' && remL > 0)
	{
		char save = s[i];
		s[i] = ' ';
		permute(s, i + 1, remL - 1, remR, open);
		s[i] = save;
	}
	//remove current ')'
	if (c == ')' && remR > 0)
	{
		char save = s[i];
		s[i] = ' ';
		permute(s, i + 1, remL, remR - 1, open);
		s[i] = save;
	}
	//keep char
	if (c == '(')
		permute(s, i + 1, remL, remR, open + 1);
	else if (c == ')')
	{
		if (open > 0)
			permute(s, i + 1, remL, remR, open - 1);
	}
	else
		permute(s, i + 1, remL, remR, open);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	int	L = 0, R = 0;
	int open = 0;
	for (int i = 0; argv[1][i]; i++)
	{
		if (argv[1][i] == '(')
			open++;
		else if (argv[1][i] == ')')
		{
			if (open == 0)
				R++;
			else
				open--;
		}
	}
	L = open;
	permute(argv[1], 0, L, R, 0);
	return (0);
}

