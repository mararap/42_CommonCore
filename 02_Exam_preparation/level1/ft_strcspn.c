
#include <aio.h>

size_t ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;

    while (s[i])
    {
        while(reject[j])
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
        j = 0;
    }
    return (i);
}

#include <stdio.h>
#include <string.h>

int main (int ac, char **av)
{
    (void)ac;
    size_t result = 0;
    const char *s = (const char *)av[1];
    const char *reject = (const char *)av[2];

    result = ft_strcspn(s, reject);
    printf("own result = %zu\n", result);
    result = strcspn(s, reject);
    printf("ori result = %zu\n", result);
    return (0);
} 
