
#include <unistd.h>

int is_doub(char *str, char c, int i)
{
    i--;
    while(i >= 0)
    {   
        if (str[i] == c)
            return (1);
        i--;
    }
    return (0);
}

int main(int ac, char **av)
{   
    if (ac != 3)
        return (write(1, "\n", 1), 1);
    int     i = 0;
    int     j = 0;
    char    *s1 = av[1];
    char    *s2 = av[2];

    while (s1[i]) 
    {
        j = 0;
        while (s2[j])
        { 
            if ((s1[i] == s2[j]) &&
			(is_doub(s1, s1[i], i) == 0) &&
            (is_doub(s2, s1[i], j) == 0))
                write(1, &s1[i], 1);
            j++;
        }       
        i++;
    }
    return (0); 
}
