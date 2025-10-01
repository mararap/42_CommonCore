
#include <unistd.h> 
 
void    ft_putstr(char *str) 
{ 
    int i = 0; 
     
    while (str[i]) 
    { 
        write(1, &str[i], 1); 
        str++; 
    } 
} 
/* 
int main (int ac, char **av) 
{ 
    if (ac != 2) 
        return (1); 
    char *str = av[1]; 
     
    ft_putstr(str); 
    return (0); 
}*/
