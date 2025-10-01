
int ft_strlen(char *str)
{
    int len = 0;

    while (str[len])
        len++;
    return (len);
}

#include <stdio.h>

int main()
{
    char *str = "this is 21 chars long";

    printf("str = %s\n", str);
    printf("len = %d\n", ft_strlen(str));
}
