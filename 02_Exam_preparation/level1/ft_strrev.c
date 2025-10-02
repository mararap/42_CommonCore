
char    *ft_strrev(char *str)
{
    int i = 0;
    int j = 0;
    char    tmp;

    while (str[i])
        i++;
    i--;
    tmp = str[0];
    while (i > j)
    {
        tmp = str[j];
        str[j] = str[i]; 
        str[i] = tmp;
        j++;
        i--;
    }
    return(str);
}

#include <stdio.h>

int main(int ac, char **av)
{
    (void)ac;
    char    *str = av[1];
    char    *result;

    result = ft_strrev(str);
    printf("own  = %s\n", result);
    return (0);
}
