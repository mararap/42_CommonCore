
#include <unistd.h>

char    *ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i])
    {
        j = 0;
        while(s2[j])
        {       
            if (s1[i] == s2[j])
                return((char *)&s1[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}

#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
    (void)ac;
    char    *str = av[1];
    char    *accept = av[2];
    char    *result;

    result = ft_strpbrk(str, accept);
    printf("own  = %s\n", result);
    result = strpbrk(str, accept);
    printf("ori  = %s\n", result);
    return (0);
}
