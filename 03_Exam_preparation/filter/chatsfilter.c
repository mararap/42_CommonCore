#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 4096

static void print_error(const char *msg)
{
    write(2, "Error: ", 7);
    perror(msg);
}

static void censor_and_write(char *str, char *filter)
{
    size_t filter_len = strlen(filter);
    size_t str_len;
    char *match;

    while (*str)
    {
        str_len = strlen(str);
        match = memmem(str, str_len, filter, filter_len);

        if (!match)
            break;

        // print everything before the match
        write(1, str, match - str);

        // print stars for the filter
        for (size_t i = 0; i < filter_len; i++)
            write(1, "*", 1);

        str = match + filter_len;
    }

    // print the tail
    write(1, str, strlen(str));
}

int main(int ac, char **av)
{
    if (ac != 2 || strlen(av[1]) == 0)
        return (1);

    char *filter = av[1];
    char buffer[BUF_SIZE];
    ssize_t bytes_read;

    // Read from stdin in chunks
    while ((bytes_read = read(0, buffer, BUF_SIZE)) > 0)
    {
        // Null-terminate the chunk to use memmem safely
        buffer[bytes_read] = '\0';

        // Process and print
        censor_and_write(buffer, filter);
    }

    if (bytes_read < 0)
    {
        print_error("read");
        return (1);
    }

    return (0);
}

