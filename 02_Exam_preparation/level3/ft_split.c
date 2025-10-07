
#include <stdlib.h>

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	word_count(char *str)
{
	int		i = 0;
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
			while (str[i] && (ft_isspace(str[i]) == 0))
				i++;
		}
	}
	return (count);
}

char	**ft_split(char	*str)
{
	int	i = 0;
	int	j = 0;
	int	k;
	int	len;
	char **arr;
	int count = word_count(str);
	arr = (char **)malloc((count + 1) * sizeof(char *));

	if (!arr)
		return (NULL);
	while (str[i] && j < count)
	{
		while (ft_isspace(str[i]))
			i++;
		len = 0;
		while (str[i + len] && !ft_isspace(str[i + len]))
			len++;
		arr[j] = malloc((len + 1) * sizeof(char));
		if (!arr[j])
			return (NULL);
		k = 0;
		while (k < len)
		{
			arr[j][k] = str[i + k];
			k++;
		}
		arr[j][k] = '\0';
		i += len;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	char *str = av[1];
	char **arr = ft_split(str);
	int	count = word_count(str);
	int	i = 0;
	
	while (i < count)
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return (0);
}	
