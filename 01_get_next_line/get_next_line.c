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

static char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(s1 || s2))
		return (NULL);
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	free(s1);
	return (newstr);
}

static char	*ft_save(char *saved, size_t i)
{
	char	*new_saved;

	if (!saved)
		return (free(saved), NULL);
	new_saved = ft_substr(saved, i + 1, ft_strlen(saved) - (i + 1));
	if (!new_saved)
		return (free(saved), NULL);
	free (saved);
	return (new_saved);
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
	char	*new_saved;

	bytesread = 1;
	if (!saved)
		saved = ft_strdup("");
	if (!saved)
		return (NULL);
	temp = (char *)malloc(BUFFER_SIZE + 1); 
	if (!temp)
		return (free(saved), NULL);
	while (bytesread > 0)
	{
		if (saved && ft_strchr(saved, '\n'))
			break ;
		bytesread = read(fd, temp, BUFFER_SIZE);
		if (bytesread <= 0)
			break ;
		temp[bytesread] = '\0';
		new_saved = ft_strjoin_free(saved, temp);
		if (!new_saved)
			return (free(temp), NULL);
		saved = new_saved;
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
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	while (saved[i] && saved[i] != '\n')
		i++;
	line = ft_lncpy(saved, i);
	saved = ft_save(saved, i);
	if (!saved)
		return (line);
	return (line);
}
