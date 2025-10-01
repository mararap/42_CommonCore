
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 2)
        return(write(1, "\n", 1), 1);

    int i = 0;
    char *str = av[1];

    while (str[i] && str[i + 1] != '\0')
    {
        if ((str[i] >= 'A' && str[i] <= 'M') ||
            (str[i] >= 'a' && str[i] <= 'm'))
            str[i] += 13;
        else if ((str[i] >= 'N' && str[i] <= 'Z') ||
            (str[i] >= 'n' && str[i] <= 'z'))
            str[i] -= 13;
        write (1, &str[i], 1);
        i++;
    }
    write (1, "\n", 1);
    return (0);
}
