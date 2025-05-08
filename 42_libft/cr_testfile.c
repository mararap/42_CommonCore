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
#include <ctriterion/criterion.h>
#include "libft.h"

Test(chars, test_against_original_function)
{
	cr_assert_eq(ft_isalpha.c, isalpha.c > 0, "does not match");
}


