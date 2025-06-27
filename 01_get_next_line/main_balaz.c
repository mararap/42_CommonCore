#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd;
	char *line;

    fd = open("test_regular_text.txt", O_RDONLY);
	for (int i = 0; i < 11770; i++)
		printf("%s", get_next_line(fd));
/*	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}*/
	close (fd);
	return (0);
}