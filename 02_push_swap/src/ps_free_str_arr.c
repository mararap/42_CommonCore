/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:58:26 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/11 15:23:27 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_free_str_arr(char **str_arr)
{
	size_t	i;
	
	i = 0;
	while(str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	str_arr = NULL;
}
