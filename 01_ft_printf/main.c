#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int i = 97;
    char *s = "hello";

    printf("\n%i\n", ft_printf(NULL));
    printf("\n%i\n",    printf(NULL));
}