/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:58:03 by netrunner         #+#    #+#             */
/*   Updated: 2025/10/07 10:58:06 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE //for string.h
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char *get_next_line(int fd, int *error)
{
	static char buf[BUFFER_SIZE];
	static int i = 0, bytes = 0;
	char *line;
	int j = 0;

	line = calloc(10000, 1);
	if (!line)
	{
		perror("Error: ");
		*error = 1;
		return (NULL);
	}
	while (1)
	{
		if (i >= bytes)
		{
			i = 0;
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes <= 0)
			{
				if (bytes < 0)
				{
					perror("Error: ");
					free(line);
					*error = 1;
					return (NULL);
				}
				break ;
			}
		}
		line[j++] = buf[i++];
		if (line[j - 1] == '\n')
			break ;
	}
	if (j)
	{
		line[j] = 0;
		return (line);
	}
	else
	{
		free(line);
		line = NULL;
		i = 0;
		bytes = 0;
		return (NULL);
	}
}

void filter_line(char *line, char *filter)
{
	const char *p = line;
	char *match;
	int len_filter = strlen(filter);
	int len_p = strlen(p);

	while(*p)
	{
		if (!(match = memmem(p, len_p, filter, len_filter)))
		{
			write(1, p, len_p);
			return ;
		}
		else
		{
			write(1, p, match - p);
			int i = 0;
			while (i < len_filter)
			{
				write(1, "*", 1);
				i++;
			}
			p = match + len_filter;
			len_p = strlen(p);
		}
	}
}

int	main(int ac, char **argv)
{
	char	*line;
	int 	error = 0;

	if (ac != 2 || argv[1][0] == '\0')
		return (1);
	while ((line = get_next_line(0, &error)))
	{
		filter_line(line, argv[1]);
		free(line);
	}
	if (error == 1)
		return (1);
	return (0);
}
