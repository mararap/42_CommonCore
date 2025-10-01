
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 2)
        return (write(1, "\n", 1), 1);

    int  i = 0;
    char *str = av[1];

    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'y') ||
            (str[i] >= 'A' && str[i] <= 'Y'))
            str[i] = str[i] + 1;
        else if (str[i] == 'z')
            str[i] = 'a';
        else if (str[i] == 'Z')
            str[i] = 'A';
        write (1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
