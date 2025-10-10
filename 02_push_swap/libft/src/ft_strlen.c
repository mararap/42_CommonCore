/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:58:32 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/10 21:51:55 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	str[] = "asdfjklö";
	
	printf("Length of \"%s\" is: %zu\n", str, strlen(str));
	printf("Length of \"%s\" is: %zu\n", str, ft_strlen(str));
	return (0);
}*/
