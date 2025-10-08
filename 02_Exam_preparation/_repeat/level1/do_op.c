
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac != 4)
        return (write(1, "\n", 1), 1);

    int result = 0;
    char operator = av[2][0];
    int num1 = atoi(av[1]);
    int num2 = atoi(av[3]);

    if (operator == '*')
        result = num1 * num2;
    else if (operator == '/')
        result = num1 / num2;
    else if (operator == '+')
        result = num1 + num2;
    else if (operator == '-')
        result = num1 - num2;
    else if (operator == '%')
        result = num1 % num2;
    printf("%d", num1);
    printf(" %c ", operator);
    printf("%d", num2);
    printf(" = ");
    printf("%d\n", result);
    return (0);
}
