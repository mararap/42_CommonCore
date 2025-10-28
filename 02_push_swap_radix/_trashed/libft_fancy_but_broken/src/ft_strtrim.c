/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:41:13 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/11 18:03:37 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[start] && ft_strchr(set, (int)s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (s1[end] && ft_strchr(set, (int)s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
/*
#include <stdio.h>

int	main(void)
{
	const char *s1 = NULL;
	const char *set = "xy-";
	char *result = ft_strtrim(s1, set);

	printf("trimmed string: %s\n", result);
	free(result);
	return (0);
}*/
