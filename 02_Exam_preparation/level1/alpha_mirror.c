
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 2)
        return (write(1, "\n", 1), 1);

    int i = 0;
    char *str = av[1];

    while (str[i])
    {
        if ((str[i] >= 'A' && str[i] <= 'M'))
            str[i] = 'N' + ('M' - str[i]);

        else if ((str[i] >= 'a' && str[i] <= 'm'))
            str[i] = 'n' + ('m' - str[i]);

        else if ((str[i] >= 'N' && str[i] <= 'Z'))
            str[i] = 'M' - (str[i] - 'N');

        else if ((str[i] >= 'n' && str[i] <= 'z'))
            str[i] = 'm' - (str[i] - 'n');

        write (1, &str[i], 1);

        i++;
    }
    write (1, "\n", 1);
    return (0);
} 

