#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char *get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	bytes = 0;
	static int	i = 0;
	int			j = 0;
	char		*line = NULL;
	
	line = malloc(1000000);
	if (!line)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (i >= bytes)
		{
			i = 0;
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes < 0)
				return (free(line), NULL);
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
		i = 0;
		bytes = 0;
		return (NULL);
	}
	line[j] = '\0';
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char	*line = NULL;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
