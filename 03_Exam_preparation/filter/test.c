
#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE] = NULL;
	static int	byte = 0;
	static int	i = 0;
	int			j = 0;
	char		*line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || (!line = malloc(1000000)))
		return (NULL);
	while (1)
	{
		if (i >= byte)
		{
			i = 0;
			byte = read(fd, buf, BUFFER_SIZE);
			if (byte < 0)
				return(free(line), write(2, "Error: read failed\n", 19), 1);
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

void	censor(char *str, char *filter
{
	int	filter_len = strlen(filter);
	char *match = NULL;

	while (match = strstr(str, filter)

