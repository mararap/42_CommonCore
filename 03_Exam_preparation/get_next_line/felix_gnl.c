#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	char *s = malloc(100000), *c = s;
	if (!s)
		return (NULL);
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = '\0', s) : (free(s), NULL);
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
	return(0);
}
