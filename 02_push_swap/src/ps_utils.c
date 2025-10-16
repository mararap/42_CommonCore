/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:14:11 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/16 13:10:33 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ps_arr_of_str_len(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}
void	ps_handle_error(int error, t_ps *stack)
{
	free(&stack);
	ft_printf("ERROR - program terminated\nerrorcode = d%\n", error);
	exit;	
}