
#include <stdlib.h>

int	range_size(int start, int end)
{
	int	result;
	result = end - start;
	if (result == 0)
		return (1);
	if (result < 0)
		result *= -1;
	return (result + 1);
}


int	*ft_rrange(int start, int end)
{
	int	i = 0;
	int	size = range_size(start, end);
	int	*arr = malloc(size * sizeof(int));

	while (end >= start)
	{
		arr[i] = end;
		end--;
		i++;
	}
	return (arr);
}

#include <stdio.h>

int	main (int ac, char **av)
{
	(void)ac;
	int	start = atoi(av[1]);
	int end = atoi(av[2]);
	int	*arr = ft_rrange(start, end);
	int	i = 0;

	printf("start = %d\n", start);
	printf("end = %d\n", end);
	printf("arr = ");
	while(end > start)
	{
		printf("%d, ", arr[i]);
		end--;
		i++;
	}
	printf("%d\n", arr[i]);
	printf("%p\n", (void *)arr);
	free(arr);
	return (0);
}
