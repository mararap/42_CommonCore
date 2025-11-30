
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	i;
	static int	byte;
	int			j = 0;
	char		*line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line = malloc(10000000)))
		return (NULL);
	while (1)
	{
		if (i >= byte)
		{
			i = 0;
			byte = read (fd, buf, BUFFER_SIZE);
			if (byte < 0)
				return (free(line), NULL);
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

#include <stdio.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char	*line = NULL;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
