
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return(s1[i] - s2[i]);
        i++;
    }
    return (0);
}

#include <stdio.h>
#include <string.h>

int main (int ac, char **av)
{
    (void)ac;

    char *s1 = av[1];
    char *s2 = av[2];
    int result = 0;

    result = ft_strcmp(s1, s2);
    printf("own result = %d\n", result);
    result = strcmp(s1, s2);
    printf("ori result = %d\n", result);
    return (0); 
}
