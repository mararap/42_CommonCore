
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 2)
        return (write(1, "\n", 1), 1);
    
    int i = 0;
    char *str = av[1];

    while (str[i])
        i++;
    i--;
    while (i > 0)
    {
        write(1, &str[i], 1);
        i--;
    }
    write(1, &str[i], 1);
    write(1, "\n", 1);
    return (0);
} 
