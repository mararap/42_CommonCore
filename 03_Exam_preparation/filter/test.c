#define _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(fd)
{
	static char	buf[BUFFER_SIZE];
	static int	i = 0;
	static int 	bytes = 0;
	int			j = 0;
	char		*line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1000000);
	if (!line)
		return(perror("Error"), NULL);
	while(1)
	{
		if (i >= bytes)
		{
			i = 0;
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes < 0)
				return (perror("Error"), NULL);
			else if (bytes == 0)
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
		bytes = 0;
		return (NULL);
	}
	line[j] = '\0';
	return (line);
}

void	my_filter(char *str, char *filter)
{
	char *match = NULL;
	int	str_len = strlen(str);
	int	filter_len = strlen(filter);

	while (*str)
	{
		if (!(match = memmem(str, str_len, filter, filter_len)))
			return ;
		else
		{
			int i = 0;
			write(1, str, match - str);
			while (i < filter_len)
			{
				write(1, "*", 1);
				i++;
			}
			str = match + filter_len;
			str_len = strlen(str);
		}
	}
	write (1, str, strlen(str));
}

int	main(int ac, char **av)
{
	char	*line = NULL;
	if (ac != 2 || !av[1][0])
		return (1);

	while ((line = get_next_line(0)))
	{
		my_filter(line, av[1]);
		free(line);
	}
	return (0);
}
