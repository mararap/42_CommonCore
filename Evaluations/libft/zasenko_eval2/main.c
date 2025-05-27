
#include "libft.h"
#include <stdio.h>
int	main(void)
{
    int	n = -85555555;
	char *result = ft_itoa(n);

    if(!result)
    {

        return 1;
    }
	printf("newstr: %s\n", result);
	free(result);
	return (0);
}