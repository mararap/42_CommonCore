
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *str = av[1];
    char bad = av[2][0];
    char new = av[3][0];
// check for right input
    if (ac != 4)
        return(write(1, "\n", 1), 1);
// print string, replacing bad with new
    while (str[i])
    {
        if (str[i] == bad)
            str[i] = new;
        write(1, &str[i], 1);
        i++;
    }   
    write (1, "\n", 1);
    return (0);
}
