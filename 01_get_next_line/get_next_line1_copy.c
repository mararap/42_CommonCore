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

# include <string.h>
# include <stdio.h> //TODO: delete line

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*saved;
	ssize_t		bytesread;
	size_t		i;
	size_t 		j;
	char		*line;
	char		*nwln;
	char		*lstps;

	i = 0;
	j = 1;
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
		//printf("%zu\n", bytesread);
		if (bytesread == 0)
			break;
			//return (free(temp), line); //NULL-check for read
		if (bytesread == -1)
			break ; //error-check for read
		temp[bytesread] = '\0'; //set last byte to null-character
		//i = 0; // set i to 0
		saved = ft_strjoin(saved, temp);
		//printf("1: %s\n", saved);
		//printf("1: %s\n", saved); //TODO: free saved in ft_strjoin (= gnljoin o.s.)
			if(saved == NULL)
				return(free(temp), NULL);
	}
		//printf("saved: %s\n", saved);
		//free(temp);
		while (saved[i] && saved[i] != '\n')			//count for length of saved (?)
			i++;
		/* if (saved[i] == '\0')
			return NULL; */
			//nwln[j] = temp[i]; just count
		//printf("2: %zu\n", i);
			//j++;
		if (saved[0] == '\0')
			return NULL;
		if (saved[i] == '\n' || saved[i] == '\0')
		{
			line = malloc((i + 1) * sizeof(char));
			if (line == NULL)
				return(NULL); //allocate for line
			ft_strlcpy(line, saved, i + 1);
			if (saved[i] != '\0')
				line[i] = '\n';
			saved = ft_substr(saved, i + 1, ft_strlen(saved) - (i + 1));
			//printf("after substr: %s\n", saved);
		}
		//copy saved to line for the lenght of j
		//printf("3: %d\n", i);
		//printf("4: %d\n", ft_strlen(saved));
		//printf("5: %s", saved);
/* 		if (saved[i] == '\n' && temp)
			saved[i + 1] = temp[i + 1];*/
		
		//printf("6: %s", saved);
		if (saved == NULL)
		{
			if (line)
				free(line);
			free(saved); //TODO: free saved within ft_substr - got warning -> free here
			return(NULL);
			//TODO free temp where needed
		}
		//free(temp);
			//temp = NULL;
		if (line)
		{
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
			}			free(temp);

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
	//free(temp);
	return(line);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
	char 	*line;

    fd = open("text.txt", O_RDONLY);
	/* line = get_next_line(fd); */
	//printf("%s", line);
	 /* while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}  */
	for (int i = 0; i < 6; i++)
		printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}
