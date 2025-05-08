/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:09:00 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/08 10:09:06 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *memset(void *s, int c, size_t n)
{
	char	*char;
	size_t	i;

	*s = *char;
	while ((char[i] && (i <= n))
		{
		 char(i) = c;
			i++;
		}
		 return (*s);
}
