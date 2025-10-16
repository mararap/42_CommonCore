/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:54:55 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/16 12:34:26 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_isvalid(char c)
{
	if ((c == ' ') || ft_isdigit(c) || (c == '-') || (c == '+'))
		return (1);
	return (0);
}
int	ps_isvalid_sign(char c, char b)
{
	if (!ft_isdigit(b) || b == '0')
		return (0);
	else
		return (c * 1);	
}
int	ps_doub(int *arr, int num, int i)
{
	int	j;
	
	j = 0;
	while(j < i)
	{
		if(arr[j] == num)
			return(1);
		j++;
	}
	return (0);
}
