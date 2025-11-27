
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

static int ft_strncmp(const char *a, const char *b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*filter;
	int		flen;
	char	*win = NULL;
	char	*stars = NULL;
	int		wlen = 0;
	ssize_t	r;
	char	c;
	int		i;

	if (ac != 2 || av[1] == NULL || strlen(av[1]) == 0)
		return (1);
	filter = av[1];
	flen = (int)strlen(filter);
	win = malloc((size_t)flen + 1);
	if (win == NULL)
	{
		perror("Error\n");
		return (1);
	}
	stars = malloc((size_t)flen + 1);
	if (stars == NULL)
	{
		free(win);
		perror("Error\n");
		return (1);
	}
	i = 0;
	while (i < flen)
	{
		stars[i] = '*';
		i++;
	}
	stars[flen] = '\0';
	wlen = 0;
	while ((r = read(0, &c, 1)) > 0)
	{
		win[wlen++] = c;
		if (wlen == flen)
		{
			if (ft_strncmp(win, filter, flen))
			{
				ssize_t w = write (1, stars, (size_t)flen);
				if (w != flen)
				{
					free(win);
					free(stars);
					perror("Error\n");
					return (1);
				}
				wlen = 0;
			}
			else
			{
				if (write (1, &win[0], 1) != 1)
				{
					free(win);
					free(stars);
					perror("Error\n");
					return (1);
				}
				i = 0;
				while (i < flen - 1)
				{
					win[i] = win[i + 1];
					i++;
				}
				wlen = flen - 1;
			}
		}
	}
	if (r == -1)
	{
		free(win);
		free(stars);
		perror("Error\n");
		return (1);
	}
	if (wlen > 0)
	{
		if (write(1, win, (size_t)wlen) != wlen)
		{
			free(win);
			free(stars);
			perror("Error\n");
			return (1);
		}
	}
	free(win);
	free(stars);
	return (0);
}