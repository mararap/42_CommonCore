
#include <fcntl.h>     // open
#include <stdlib.h>    // free, exit
#include <unistd.h>    // close
#include <stdio.h>     // printf
#include "get_next_line.h"
/*
int main() //Balaz
{
    int fd;
	char *line;

    fd = open("test_regular_text.txt", O_RDONLY);
	for (int i = 0; i < 11770; i++)
		printf("%s", get_next_line(fd));*/
/*	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}*/
/*	close (fd);
	return (0);
}*/

int main(int argc, char **argv)
{
     int     file_descriptor;
     char    *next_line;
     int     i;

     i = 0;
     if (argc != 1 + 1)
     {
        write (2, "Error.\n", 7);
        return (-1);
     }

     file_descriptor = open(argv[1], O_RDONLY);
     if (file_descriptor == -1)
     {
         printf("Error opening the file");
         return (1);
     }
     while (1)
     {
         next_line = get_next_line(file_descriptor);
         if (next_line == NULL)
             break ;
         i++;
         printf("[%d]: %s", i, next_line);
         free (next_line);
         next_line = NULL;
     }
     close(file_descriptor); // Close the file
     return (0);
}

/*int main(void)
{
	int fd;
	char *line;
	int i = 2;

	fd = open("test_regular_text.txt", O_RDONLY);
	if (fd == 0)
	{
		perror("Fehler beim Öffnen der Datei");
		return (2);
	}

	line = get_next_line(fd);
	while (line)
	{
		printf("Zeile %d: %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	line = NULL;
	close(fd);
	return (1);
}*/
