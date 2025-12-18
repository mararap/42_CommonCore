
#define _GNU_SOURCE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE];
	static int bytes;
	static int i;
	int j = 0;
	char *line = NULL;

	line = malloc(1000000);
	if (!line)
		return(perror("Error"), NULL);
	while (1)
	{
		if (i >= bytes)
		{
			i = 0;
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes < 0)
				return(free(line), perror("Error"), NULL);
			else if (bytes == 0)
				break ;
		}
		line[j++] = buf[i++];
		if (line[j - 1] == '\n')
			break ;
	}
	if (j == 0)
		return(free(line), NULL);
	line[j] = '\0';
	return (line);
}

void my_filter(char *str, char *filter)
{
	size_t len = strlen(filter);
	char *m, stars[100] = {0};

	memset(stars, '*', len);
	while ((m = memmem(str, strlen(str), filter, len)))
	{
		write(1, str, m - str);
		write(1, stars, len);
		str = m + len;
	}
	write(1, str, strlen(str));
}

int main(int ac, char **av)
{
	char *line = NULL;

	if(ac != 2 || !av[1][0])
		return (1);
	while ((line = get_next_line(0)))
	{
		my_filter(line, av[1]);
		free(line);
	}
	return (0);
}
