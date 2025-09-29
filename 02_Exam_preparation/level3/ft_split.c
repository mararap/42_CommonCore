/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:55:55 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/29 19:59:41 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	word_count(char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '	' || str[i] == '\n'))
			i++;
		if(str[i] && (str[i] != ' ' && str[i] != '	' && str[i] != '\n'))
		{
			count++;
			while (str[i] && (str[i] != ' ' && str[i] != '	' && str[i] != '\n'))
				i++;
		}
	}
	return (count);
}

char **ft_split(char *str)
{
	int	i = 0;
	char **arr = NULL;
	int j = 0;
	int	len = 0;
	int count = word_count(str); // count the words
	arr = malloc(count); // allocate for array
	while (str[i] && j <= count) // skip spaces, count chars, allocate for str, fill str
	{
		while (str[i] && (str[i] == ' ' || str[i] == '	' || str[i] == '\n'))
			i++;
		while (str[i] && (str[i] != ' ' && str[i] != '	' && str[i] != '\n'))
		{
			i++;
			len++;
		}
		arr[j] = malloc(len + 1); // allocate for first string
		len -= 1; // shoult be at first space after word, want it to be at last letter
		while (len >= 0)
		{
			arr[j][len] = str[len];
			len--;
		}
		j++;
	}
	return (arr);		
}

int main (int ac, char **av)
{
	(void)ac;
	char *str = av[1];

	return (0);
}
