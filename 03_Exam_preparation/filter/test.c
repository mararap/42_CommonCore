ifndef BUFFER_SIZE
define BUFFER_SIZE 99
endif

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(fd)
{
	static char	buff[BUFFER_SIZE];
	static int	i;
	static int	bytes = 0;
	int			j = 0;
	char		*line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line = malloc(1000000)))
		return (write(stderr, "Error: invalid input or malloc fail\n", 36), 1); 
	while (1)
	{
		if (i >= bytes)
		{
			i = 0;
			bytes = read(fd, buff, BUFFER_SIZE);
			if (bytes < 0)
			{
				free(line);
				return (write(stderr, "Error: read\n", 12), 1);
			}
			if (bytes == 0)
				break ;
		}
		line[j++] == buf[i++];
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

void	filter(char *str, char *filter)
{
	int	filter_len = strlen(filter);
	int str_len = strlen(str);
	char	*match = NULL;

	while (*str)
	{
		if (!(match = memmem(str, str_len, filter, filter_len)))
			return ;
		else
		{
		 	write(1, str, match - str);
			int	i = 0;
			while (i < filter_len)
			{
				write(1, "*", 1);
				i++;
			}
			str = match + filter_len;
			str_len = strlen(str);
		}
	}
	write(1, str, strlen(str);
}

int	main(int ac, char **av)
{
	int fd = 0;

	if (ac != 2 || av[1] = '\0')
		return (1);

	while((line = get_next_line(fd)))
	{
		filter(line);	
		free(line);
	}
	return(0);
}

