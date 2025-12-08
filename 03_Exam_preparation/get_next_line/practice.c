
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(fd)
{
	static char	buf[BUFFER_SIZE];
	static int	bytes = 0;
	static int	i = 0;
	char		*line = NULL;
	int			j = 0;

	line = malloc(1000000);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return(NULL);
	while(1)
	{
		if(i >= bytes)
		{
			i = 0;
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes < 0)
				return (free(line), NULL);
			if (bytes == 0)
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

#include <stdio.h>

int	main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	char	*line = NULL;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return(0);
}

