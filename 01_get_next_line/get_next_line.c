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

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (free(newstr), NULL);
	while (s1[i] && i <= ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}

static char	*ft_save(char *saved, size_t i)
{
	char	*temp;

	temp = ft_substr(saved, i + 1, ft_strlen(saved) - (i + 1));
	free (saved);
	return (temp);
}

static char	*ft_lncpy(char *saved, size_t i)
{
	char	*line;

	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, saved, i + 2);
	return (line);
}

static char	*ft_read_write(int fd, char *saved)
{
	ssize_t	bytesread;
	char	*temp;

	bytesread = 1;
	if (!saved)
		saved = ft_strdup("");
	temp = (char *)malloc(BUFFER_SIZE + 1); 
	if (!temp)
		return (NULL);
	while (bytesread > 0)
	{
		if (ft_strchr(saved, '\n'))
			break ;
		bytesread = read(fd, temp, BUFFER_SIZE);
		if (bytesread == 0)
			break ;
		if (bytesread == -1)
			break ;
		temp[bytesread] = '\0';
		saved = ft_strjoin(saved, temp);
		if (saved == NULL)
			return (free(temp), NULL);
	}
	return (free(temp), saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	size_t		i;
	char		*line;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = ft_read_write(fd, saved);
	if (!saved || saved[0] == '\0')
		return (free(saved), saved = NULL, NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	line = ft_lncpy(saved, i);
	if (!line)
		return (free (saved), NULL);
	saved = ft_save(saved, i);
	if (!saved)
		return (free(saved), line);
	return (line);
}
