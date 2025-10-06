
#include <stdlib.h>

int	word_count(char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '	' || str[i] == '\n'))
			i++;
		if(str[i] && (str[i] != ' ' && str[i] != '	' && str[i] != '\n'))
		{
			count++;
			while (str[i] && (str[i] != ' ' && str[i] != '	' && str[i] != '\n'))
				i++;
		}
	}
	return (count);
}

char **ft_split(char *str)
{
	int	i = 0;
	char **arr = NULL;
	int j = 0;
	int	len = 0;
	int reset_i = 0;
	int count = word_count(str); // count the words
	arr = (char **)malloc(count * sizeof(char *)); // allocate for array
	while (str[i] && j < count) // skip spaces, count chars, allocate for str, fill str
	{
		while (str[i] && (str[i] == ' ' || str[i] == '	' || str[i] == '\n'))
			i++;
		while (str[i] && (str[i] != ' ' && str[i] != '	' && str[i] != '\n'))
		{
			i++;
			len++;
		}
		reset_i = i; // save index at space after word
		i--;
		len--;
		arr[j] = malloc(len + 2); // allocate for string
		while (len >= 0)
		{

			arr[j][len] = str[i];
			len--;
			i--;
		}
		len++; // len after loop = -1
		i = reset_i; // reset i to space after word
		j++;
	}
	return (arr);		
}

#include <stdio.h>

int main (int ac, char **av)
{
	(void)ac;
	char **arr = NULL;
	int count = 0;
	int	i = 0;	
	char *str = av[1];
	arr = ft_split(str);
	count = word_count(str);
	while (i < count)
	{
		printf("%d\n", i);
		printf("%s\n", arr[i]);
		i++;
	}
	return (0);
}
