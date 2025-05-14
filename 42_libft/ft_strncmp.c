/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:30:10 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/14 13:30:15 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i <= n)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char s1[42] = "if you're happy and you know it...";
	const char s2[42] = "if you know it and you're happy...";
	size_t n = 15;
	
	printf("mine: %d\n", strncmp(s1, s2, n));
	printf("original: %d\n", strncmp(s1, s2, n));
}*/
