/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:35:06 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/17 20:15:02 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	check = 1;

	while (check <= n)
	{
		if (check == n)
			return (1);
		check = check * 2;
	}
	return (0);
}

int main()
{
	unsigned int n = 4097;
	printf("1 is yes\n0 is no\nresult = %d\n", is_power_of_2(n));
	return(0);
}
