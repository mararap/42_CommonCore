#ifndef BUFFER_SIZE
# define BUFFER_SIZE 99
#endif

#define _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>

char	*get_next_line(int fd/*, int *error*/)
{
	static char	buff[BUFFER_SIZE];
	static int	i;
	static int	bytes = 0;
	int			j = 0;
	char		*line = NULL;
//	(void)error;

	if (!(line = malloc(1000000)))
		return (perror("Error"), NULL);
	while (1)
	{
		if (i >= bytes)
		{
			i = 0;
			bytes = read(fd, buff, BUFFER_SIZE);
			if (bytes < 0)
			{
				free(line);
				break ;
			}
			if (bytes == 0)
				break ;
		}
		line[j++] = buff[i++];
		if (line[j - 1] == '\n')
			break ;
	}
	if (j == 0)
	{
		free(line);
		line = NULL;
		i = 0;
		bytes = 0;
		return (NULL);
	}
	line[j] = '\0';
	return (line);
}

void	filter(char *str, char *filter)
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
			int	i = 0;
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

int	main(int ac, char **av)
{
	int fd = 0;
	char *line;
//	int	error = 0;


	if (ac != 2 || *av[1] == '\0' || fd < 0 || BUFFER_SIZE <= 0)
		return (1);

	while((line = get_next_line(fd/*, &error*/)))
	{
		filter(line, av[1]);
		free(line);
	}
//	if (error != 0)
		
	return(0);
}
