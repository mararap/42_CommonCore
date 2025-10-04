
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 2 || av[1][0] == '\0')
        return (write(1, "\n", 1), 1);

    int i = 0;
    char *str = av[1];
    
    while (str && str[i])
    {   
        while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
            i++;
        while (str[i] != 32 && !(str[i] >= 9 && str[i] <= 13))
        {       
            write (1, &str[i], 1);
            i++;
        }
        if (str[i] == '\0')
        {
            write (1, "\n", 1);
            return (0);
        }
        while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
            i++;
        if (str[i] == '\0')
            write (1, "\n", 1);
        else
            write (1, " ", 1); 
    }
    return (0);
}
