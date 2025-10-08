
int ft_atoi(const char *str)
{   
    int i = 0;
    int num = 0; 
    int factor = 0;
    int sign = 1;

    while (str[i] && (str[i]  == 32 || (str[i] <= 13 && str[i] >= 9)))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
        i++;
    i--;
    num = str[i] - '0';
    i--;
    factor = 10;
    while (i >= 0 && (str[i] >= '0' && str[i] <= '9'))
    {
        num += (str[i] - '0') * factor;
        factor *= 10;
        i--;
    }
    return (num * sign);
}

#include <stdio.h>

int main (int ac, char **av)
{
    if (ac != 2)
        return (printf("\n"), 1);

    int num = 0;

    num = ft_atoi(av[1]);
    printf("Num = %d", num);
    return (0);
}
