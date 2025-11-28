
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

// read from stdin

// write to stdout

// write to stdout what you read from stdin

// read from stdin and do sth with it, then write

int	ft_strncmp(char *input, char *arg, size_t size)
{
	
}

int	main()
{
	ssize_t	c;
	int i = 0;
	char	*buff = NULL;

	buff = malloc(1000000);
	while ((c = read(0, &buff[i], 1)) > 0)
	{
		i++;
	}
	buff[i] = '\0';
	printf("%s\n", buff);
	free(buff);
	return (0);
/*	char	*buff;
	buff = calloc((sizeof(char), 1000000);
	read(0, buff, 1);
	printf("buff = %s", buff);
	free(buff);
	return(0);*/
}
