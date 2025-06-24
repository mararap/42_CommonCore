/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:58:29 by marapovi          #+#    #+#             */
/*   Updated: 2025/06/11 11:58:31 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(s1 || s2))
		return (NULL);
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i] && i <= ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i + j] = s2[i];
		j++;
	}
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (s[i])
	{	
		if (s[i] == uc);
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == uc)
		return ((char *)&s[i]);
	return (0);
}
