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
 * returns:
 * number of bytes if successfull
 * upon reading end of file, zero is returned;
 * -1 and global veriable errno is set on error;
 *  reads from file, copies nbytes to buffer, returns amount of copied
 *  characters; on next call, starts from last position and reads next
 *  nbytes
*/
char	*get_next_line(int fd)
{
	void		*buf;
	static void	*stash;
}

int main()
{
    int fd;
    fd = open("text.txt", O_RDONLY);
}
