/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:36:28 by netrunner         #+#    #+#             */
/*   Updated: 2025/11/30 19:20:55 by marapovi         ###   ########.fr       */
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

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int i = 0, bytes = 0;
	char *line;
	int j;

	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !(line = malloc(10000)))
		return (write(1, "Error\n", 6), NULL);
	while (1)
	{
		if (i >= bytes)
		{
			i = 0;
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes <= 0)
			{
				if (bytes < 0)
					return (free(line), write(1, "Error\n", 6), NULL);
					break ;
			}
		}
		line[j++] = buffer[i++];
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

void	censor(char *str, char *filter)
{
	int filter_len = strlen(filter);
	int str_len = strlen(str);
	char * match;

	while (*str)
	{
		if (!(match = memmem(str, str_len, filter, filter_len)))
		{
			write(1, str, str_len);
			return ;
		}
		else
		{
			write(1, str, match - str);
			int i = 0;
			while (i < filter_len)
			{
				write(1, "*", 1);
				i++;
			}
			str = match + filter_len;
		}
	}
}

int	main(int ac, char **av)
{
	char	*line;

	if (ac != 2)
		return (write(1, "Error\n", 6), 1);
	while ((line = get_next_line(0)))
	{
		censor(line, av[1]);
		free(line);
	}
	return (0);
}
