
#include <stdlib.h>

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	word_count(char *str)
{
	int	i = 0;
	int 	count = 0;

	if (!str)
		return(0);
	while (str[i])
	{
		while(str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
		{
			count++;
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
	return (count);
}

char	**ft_split(char	*str)
{
	int	i = 0;
	char **arr;
	int	j = 0;
	int	len = 0;
	int reset_i = 0;
	int count = word_count(str);
	arr = (char **)malloc(count * sizeof(char *));

	while (str[i] && j < count)
	{
		while (ft_isspace(str[i]) == 1)
			i++;
		while (ft_isspace(str[i]) == 0)
		{
			i++;
			len++;
		}
		reset_i = i;
		i--;
		len--;
		arr[j] = malloc(len * sizeof(char) + 2);
		while (len >= 0)
		{
			arr[j][len] = str[i];
			len--;
			i--;
		}
		len++;
		i = reset_i;
		j++;
	}
	return (arr);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	char **arr = NULL;
	int	count = 0;
	int	i = 0;
	char *str = av[1];
	arr = ft_split(str);
	count = word_count(str);
	while (i < (count - 1))
	{
		printf("%s\n", arr[i]);
		i++;
	}
	printf("%s\n", arr[i]);
	return (0);
}		
