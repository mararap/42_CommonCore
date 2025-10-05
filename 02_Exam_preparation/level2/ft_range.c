
int	*ft_range(int start, int end)
{
	int	size = range_size(start, end);
	int	i = 0;
	int	*arr = malloc(size * sizeof(int));

	if (!arr)
		return(NULL);
	if (start == end)
		arr[i] = start;
	while (start <= end)
	{
		arr[i] = start;
		start++;
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
	int	i = 0;
	int	*arr = ft_range(start, end);

	printf("start = %d\n", start);
	printf("end = %d\n", end);
	printf("pointer = %p\n", (void *)arr);
	printf("range = ");
	while (start < end)
	{
		printf("%d, ", arr[i]);
		start++;
		i++;
	}
	printf("%d\n", arr[i]);
	free(arr);
	return (0);	
}
