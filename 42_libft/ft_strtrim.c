/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:41:13 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/18 14:41:18 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*newstr;

	start = 0;
	end = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[start] && ft_strchr(set, (int)s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strrchr(set, (int)s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

#include <stdio.h>

int	main(void)
{
	const char *s1 = "xxxyyxx---testingxxyx-xxxy";
	const char *set = "xy-";

	printf("trimmed string: %s\n", ft_strtrim(s1, set));
	return (0);
}
