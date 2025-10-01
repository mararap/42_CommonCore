
void    ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

#include <stdio.h>
#include <stdlib.h>

int main (int ac, char **av)
{
    if (ac != 3)
        return (printf("\n"), 1);

    int a = atoi(av[1]);
    int b = atoi(av[2]);

    printf("input: %d, %d\n", a, b);
    
    ft_swap(&a, &b);
    
    printf("swapped: %d, %d\n", a, b);
}
