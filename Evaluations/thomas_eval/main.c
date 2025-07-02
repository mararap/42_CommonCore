#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int     main(void) //Dominic
{
    int     fd = open("empty.txt", O_RDONLY);
    char    *s = NULL;

    if (fd <  0)
        return (1);
    while ((s = get_next_line(fd)))
    {
        printf("%s", s);
        free(s);
    }
    close(fd);
    return (0);
}

