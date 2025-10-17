/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:54:55 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/17 20:41:19 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_isvalid(char c)
{
	if ((c != ' ') && !ft_isdigit(c) && (c != '-') && (c != '+'))
		ps_handle_error(11);
}
int	ps_isvalid_sign(char c, char b)
{
	if (!ft_isdigit(b) || b == '0')
		return (ps_handle_error(12), 1);
	else
		return (c * 1);	
}
void	ps_doub(int *arr, int num, int i)
{
	int	j;
	
	j = 0;
	while(j < i)
	{
		if(arr[j] == num)
			ps_handle_error(13);
		j++;
	}
}
