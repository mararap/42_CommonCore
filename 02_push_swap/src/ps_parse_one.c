/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:27:44 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/11 16:47:55 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **ps_parse_one(char *str, int *error)
{
	int i;
	char *temp;
	char **str_split;

	i = 0;
	// allocate space for temporary char-string "temp"
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!temp)
		*error = 1;
	// check for validity while copying chars to temp
	while (str[i] && temp[i])
	{
		if(!ps_isvalid(str[i]))
			*error = 1;
		temp[i] = str[i];
		i++;
	}
	// set last character to be '\0'
	temp[i] = '\0';
	// split the copied string temp into an array of char-str "str_split"
	str_split = ft_split(temp, ' ');
	if (!str_split)
		*error = 1;
	free (temp);
	return (str_split);
}
