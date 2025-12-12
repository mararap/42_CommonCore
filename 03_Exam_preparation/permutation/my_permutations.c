
#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);

static void ft_putstr(char *str)
{
	write(0, str, ft_strlen(str);
	write(0, "\n", 1);
}

void	swap(char *a, char *b)
{
	char	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	permute(char *str, int left, int right)	//right = ft_strlen(argv[1]) - 1;
{
	int i = left;	//01: left = 0; 02 = 2, 
	if (left == right)	// when end of string is reached
	{
		ft_putstr(str);
		return ;
	}
	while (i <= right) // as long as end of string is not reached
	{
		swap(&str[left], &str[i]); //01: swap ADDRESS of str[left] with ADDRESS of str[i]
		permute(str, left + 1, right); //go to next character and call permute again
		swap(&str[left], &str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	permute(argv[1], 0, ft_strlen(argv[1]) - 1);
	return (0);
}
