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
	char		*buf[BUFFER_SIZE + 1];
	static char	*save;
	ssize_t		nbyte;
	size_t		i;
	char		*line;
	size_t		nwln;

	i = 0;
	line = NULL;
	save = (char *)malloc((BUFFER_SIZE + 1)sizeof(char));
	if (!save)
		return (NULL);
	nbyte = 1;
	while (nbyte > 0)
	{
		nbyte = read(fd, buf, BUFFER_SIZE);  //read+write
		if (nbyte == 0)
			return (free(save), line);
		if (nbyte == -1)
			break ;
		buf[nbyte] == '\0';

		while (buf[i] && i < nbyte)
		{
			save[i] == buf[i];
			i++;
		}
		//extract line
		while (save[i] && save[i] != '\n')
		{
			
			//count for length
		}
		if (save[i] == '\n')
			i++;
		//malloc length + 1
		ft_strlcpy(line, save, i + 1);

		//clean save


	}
	line = ft_strjoin(line, nwln);


#include <fcntl.h>

int main()
{
    int fd;

    fd = open("text.txt", O_RDONLY);
	while ()
	{
		...
		get_next_line(fd);
		...    int fd;

    fd = open("text.txt", O_RDONLY);
	while ()
	{
		...
		get_next_line(fd);
		...
	}
}

	}
}
