
char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;

    while(s1[i] && s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

#include <stdio.h>

int main(int ac, char **av)
{
    if (ac != 3)
        return (printf("\n"), 1);
    char *s1 = av[1];
    char *s2 = av[2];

    ft_strcpy(s1, s2);
    printf("dest = %s\n", s1);
    return (0);
}
