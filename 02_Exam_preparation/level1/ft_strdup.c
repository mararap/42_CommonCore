
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    char *dst;
    int i = 0;
    int len = 0;

    while (src[len])
        len++;
    dst = malloc(sizeof(char *) * len + 1);
    if (!dst)
        return (NULL);
    while (src[i])
    {
        dst[i] = src[i];
            i++;
    }
    return (dst);
}

#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
    (void)ac;
    char    *src = av[1];
    char    *dst;

    dst = ft_strdup(src);
    printf("own dst = %s\n", dst);
    dst = strdup(src);
    printf("ori dst = %s\n", dst);
    free (dst);
    return (0);
}
