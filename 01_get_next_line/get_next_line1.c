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
#include <stdio.h>
# include <string.h>
char	*get_next_line(int fd)
{
	char		*temp;
	static char	*saved = NULL;
	ssize_t		bytesread;
	size_t		i;
	size_t 		j;
	char		*line;
	char		*nwln;
	char		*lstps;

	i = 0;
	j = 0;
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
			return (free(temp), line);
		if (bytesread == -1)
			break ;
		temp[bytesread] = '\0';
		i = 0;
		saved = strcat(saved, temp); //TODO: free saved in ft_strjoin (= gnljoin o.s.)
			if(saved == NULL)
				return(free(temp), NULL);
		//printf("saved: %s\n", saved);
		//free(temp);
		while (saved[i] && saved[i] != '\n')			//count for length of saved (?)
			//nwln[j] = temp[i]; just count
			i++;
			//j++;
		if (saved[i] == '\n')
		{
			j = i = 1;
			line = malloc((i + 2) * sizeof(char));
			if (line == NULL)
				return(NULL); //allocate for line
			ft_strlcpy(line, saved, i + 1);
		}
		//copy saved to line for the lenght of j
		saved = ft_substr(saved, j, ft_strlen(saved + (i)));
		if (saved == NULL)
		{
			if (line)
				free(line);
			return(NULL); //TODO: free saved within ft_substr
			//TODO free temp where needed
		}
		if (line)
			return(line);
	}

		//delete line from saved and move reminder to beginning => linked lists?


/*		copy from j til '\0' to saved
		if (line)
		 return (free(temp), line);
		free(temp);
		
		if (temp[i] != '\0')	//meaning temp[i] must be '\n'
		{
			saved = malloc((BUFFER_SIZE - i) * sizeof(char));
			if (!saved)
				return (free(temp, NULL));	//need space for BUFFER_SIZE minus what is already written into nwln (i + 1) PLUS 1 for '\0' => =BUFFER_SIZE - i
			while (temp[i])
			{														
				saved [k] = temp[i];
				i++;
			}
		}
		free(temp);
		i = 0;
		}
	}
		while (nwln[i] && nwln[i] != '\n') //extract line
			i++;									//count for length
		if (saved[i] == '\n')
			i++;
		lstps = &saved[i];
		
		nwln = malloc((i + 1) * sizeof(char));				//malloc length + 1
		if (!nwln)
			return(free(saved), NULL);
		nwln = ft_strlcpy(nwln, saved, i + 1);				//copy saved to line

		//clean save
	...
	}
	line = ft_strjoin(line, nwln);*/
	return(line);
}



#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
	char 	*line;

    fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}
