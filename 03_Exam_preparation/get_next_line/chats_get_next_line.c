#include "my_get_next_line.h"

static char *grow(char *old, int cur_len, int add)
{
    char *new = malloc(cur_len + add + 1); /* +1 for '\0' */
    int k;

    if (!new)
        return NULL;
    for (k = 0; k < cur_len; ++k)
        new[k] = old[k];
    new[cur_len] = '\0';
    free(old);
    return new;
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int  idx = 0;
    static int  bytes = 0;

    char *line = NULL;
    int  len = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    while (1)
    {
        if (idx >= bytes)                      /* refill buffer when exhausted */
        {
            bytes = read(fd, buf, BUFFER_SIZE);
            idx = 0;
            if (bytes < 0) { free(line); return NULL; } /* read error */
            if (bytes == 0) break;                      /* EOF */
        }

        if (len % BUFFER_SIZE == 0)             /* grow in BUFFER_SIZE chunks */
        {
            line = grow(line, len, BUFFER_SIZE);
            if (!line) return NULL;             /* malloc failure */
        }

        line[len++] = buf[idx++];               /* copy one char */
        if (line[len - 1] == '\n')             /* stop on newline */
            break;
    }

    if (len == 0) { free(line); return NULL; }   /* nothing read => NULL */

    line[len] = '\0';
    return line;                                 /* caller must free() */
}

