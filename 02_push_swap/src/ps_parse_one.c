/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:27:44 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 14:59:13 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **ps_parse_one(char *str, t_ps *stack_a, t_ps *stack_b)
{
	int i;
	char *temp;
	char **str_split;

	i = 0;
	// allocate space for temporary char-string "temp"
	temp = (char *)(malloc(sizeof(char) * (ft_strlen(str) + 1)));
	if (!temp)
		ps_handle_error(stack_a, stack_b);
	// check for validity while copying chars to temp
	while (str[i])
	{
		ps_isvalid(str[i], stack_a, stack_b);
		temp[i] = str[i];
		i++;
	}
	// set last character to be '\0'
	temp[i] = '\0';
	// split the copied string temp into an array of char-str "str_split"
	str_split = ft_split((char const *)temp, 32);
	if (!str_split)
			ps_handle_error(stack_a, stack_b);
	free (temp);
	return (str_split);
}
