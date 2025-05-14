/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_testfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:27:15 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/08 14:27:20 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <criterion/new/assert.h>

TestSuite(chars);
TestSuite(strs);

Test(chars, test_against_original_function)
{
	char	c = 'X';

	cr_assert(eq(int, ft_isalpha(c), isalpha(c) != 0));
	cr_assert(eq(int, ft_isdigit(c), isdigit(c) != 0));
	cr_assert(eq(int, ft_isalnum(c), isalnum(c) != 0));
	cr_assert(eq(int, ft_isascii(c), isascii(c) != 0));
	cr_assert(eq(int, ft_isprint(c), isprint(c) != 0));
}

Test(strs, test_against_original_function)
{
	const char	str[42] = "test me if you can";
	char	*dest = "if you can, test me";
	size_t	size = 4;
	
	cr_assert(eq(int, ft_strlen(str), strlen(str) != 0));
	cr_assert(eq(int, ft_strlcpy(dest, str, size), strlcpy(dest, str, size) != 0));
}

