/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:54:55 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/11 15:23:43 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ps_isvalid(char c)
{
	if ((c == ' ') || ft_is_digit(c) || (c == '-') || (c == '+'))
		return (1);
	return (0);
}
int	ps_isvalid_sign(char c, char b)
{
	if (!ft_is_digit(b) || b == '0')
		return (0);
	else
		return (c * 1);	
}
