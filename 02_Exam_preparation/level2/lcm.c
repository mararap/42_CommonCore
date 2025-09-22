/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:49:38 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/22 17:47:09 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_hcf(unsigned int a, unsigned int b)
{
	unsigned int	hcf;
	unsigned int	big;
	unsigned int	small;
	unsigned int	remain;
	if (a > b)
		a = big, b = small;
	else if (b > a)
		b = big, a = small;
	remain = big % small;
	if (remain == 0)
		hcf = small;
	else
		hcf = hcf(small, remain);
	printf("hcf = %d\n", hcf);
	return (hcf);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	lcm;
	unsigned int	hcf;

	hcf = ft_hcf(a, b);
	lcm = (a * b) / hcf;
	return (hcf);
}
