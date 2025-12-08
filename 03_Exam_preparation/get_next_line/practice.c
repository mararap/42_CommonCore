
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	i = 0;
	static int	bytes = 0;
	int			j = 0;
	char		*line = NULL;

	line = malloc(1000000);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (NULL);

	while (1)
	{
		if (i >= bytes)	// only enters in the beginning,
		{				// or if end of buffer is reached
			i = 0;		// reset i to 0, because buffer is now empty and we
						// start filling it at idx 0
			bytes = read(fd, buf, BUFFER_SIZE);	// read from fd to buf for
												// BUFFER_SIZE bytes
			if (bytes < 0)	// means read returned an error
			{
				write(1, "Error\n", 6);
				free(line);
				return (NULL);
			}
			else if (bytes == 0)	// no more characters to read, EOF reached
				break ;				// break the infinite loop, continue to
									// end of function
		}
		line[j++] = buf[i++];		// in every other case (bytes > 0, means
									// that read returned a valid number
									// of chars), read char
		if (line[j - 1] == '\n')	// if the last character read is a '\n'
			break ;					// break the infinite loop
	}
	if (j == 0)						// means the loop was broken with bytes == 0,
									// so read returned 0 = no more characters
	{
		free(line);
		line = NULL;
		i = 0;
		bytes = 0;
		return (NULL);
	}
	line[j] = '\0';					// set last character to '\0'
	return (line);
}

#include <stdio.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char	*line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return(0);
}
