#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

// read from stdin

// write to stdout what you read from stdin

// read from stdin and do sth with it, then write

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE];
	static int	i;
	static int 	byte;
	int			j = 0;
	char		*line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line = malloc(1000000)))
		return (write(2, "Error: invalid input\n", 21), NULL);
	while (1)
	{
		if (i >= byte)
		{
			i = 0;
			byte = read(fd, buf, BUFFER_SIZE);
			if (byte < 0)
				return (free(line), write(2, "Error: read failed\n", 19), NULL);
			else if (byte == 0)
				break ;
		}
		line[j++] = buf[i++];
		if (line[j - 1] == '\n')
			break ;
	}
	if (j == 0)
	{
		free(line);
		line = NULL;
		i = 0;
		byte = 0;
		return (NULL);
	}
	line[j] = '\0';
	return (line);
}

void	censor(char *str, char *filter)
{
	int	filter_len = strlen(filter);
	int str_len = strlen(str);
	char	*match = NULL;

	while (*str)
	{
		if (!(match = memmem(str, str_len, filter, filter_len)))
			return ;
		else
		{
			write(1, str, match - str);
			int i = 0;
			while (i < filter_len)
			{
				write(1, "*", 1);
				i++;
			}
			str = match + filter_len;
			str_len = strlen(str);
		}
	}
	write(1, str, strlen(str));
}

#include <stdio.h>

int	main(int ac, char **av)
{
	char *line = NULL;

	if (ac != 2 || av[1] == '\0')
		return (1);
	while ((line = get_next_line(0)))
	{
		censor(line, av[1]);
		free(line);
	}
	return (0);
}
