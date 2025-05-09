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
#include <criterion/new/assert.h>

TestSuite(chars);

Test(chars, test_against_original_function)
{
	char	c = 'X';

	cr_assert(eq(int,ft_isalpha(c), isalpha(c) != 0));
}
