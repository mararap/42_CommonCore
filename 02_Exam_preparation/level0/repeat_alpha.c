
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 2)
        return (write(1, "\n", 1), 1);

    char *str = av[1];
    int i = 0;
    int ai = 0;

    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            ai = str[i] - 96;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            ai = str[i] - 64;
        while (ai > 0)
        {
            write(1, &str[i], 1);
            ai--;
        }
        i++;
    }
    write(1, "\n", 1);
    return(0);
}
