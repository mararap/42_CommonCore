/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:58:10 by marapovi          #+#    #+#             */
/*   Updated: 2025/06/11 11:58:13 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * extern functions: read, malloc, free;
 * "open" in main
 * read:
	 * returns number of bytes if successfull
	 * upon reading end of file, zero is returned;
	 * -1 and global veriable errno is set on error;
	 *  reads from file, copies nbytes to buffer, returns amount of copied
	 *  characters; on next call, starts from last position and reads next
	 *  nbytes
 * subject:
	* repeated calls (e.g. using a loop) should let you read the test file
	* pointed to by fd).
	* gnl should return line that was read. if there is nothing left to read
	* or if an error occurs, it should return NULL.
	* should work both when reading from a file or standard input
	* returned line should include terminating '\n', except if end of file
	* is reached and file does not end with a '\n'.
	* header file must at least contain get_next_line()
	* add helper functions to *utils.c
	* use static variable
	* compiler call:
	* cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c
	* exhibits undefined behavior if file is modified after the last call,
	* while read() has not yet reached the end of the file;
	* also exhibits undefined behavior when reading binary file;
	* BUFFER_SIZE 9999? 1? 10000000?
*/

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*saved;
	ssize_t		bytesread;
	size_t		i;
	char		*line;

	i = 0;
	if (saved == NULL)
		saved = ft_strdup("");
	line = NULL;
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, temp, BUFFER_SIZE);
		if (bytesread == 0)
			break;
		if (bytesread == -1)
			break ;
		temp[bytesread] = '\0';
		saved = ft_strjoin(saved, temp);
			if(saved == NULL)
				return(free(temp), NULL);
	}
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[0] == '\0')
		return NULL;
	if (saved[i] == '\n' || saved[i] == '\0')
	{
		line = malloc((i + 1) * sizeof(char));
		if (line == NULL)
			return(NULL);
		ft_strlcpy(line, saved, i + 1);
		if (saved[i] != '\0')
			line[i] = '\n';
		saved = ft_substr(saved, i + 1, ft_strlen(saved) - (i + 1));
	}
	if (saved == NULL)
	{
		if (line)
			free(line);
		free(saved);
		return(NULL);
	}
	if (line)
		return(line);
	return(line);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
	char 	*line;

    fd = open("regular_text.txt", O_RDONLY);
	/*while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}*/
	for (int i = 0; i < 6; i++)
		printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}
