/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:16:10 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/17 20:54:51 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	i = 1;
//	len = (int)len;
//	if(len < 0)
//		return(1);
	if(!tab[0])
		return (0);
	int result = tab[0];
	while (i < len)
	{
		if(tab[i] > result)
			result = tab[i];
		i++;
	}
	return(result);
}

int main(void)
{
	unsigned int	i = 0;
	unsigned int	len = -1;
	int tab[6] = {3, 1, 5, 8, 2, 0};

	printf("array of int = ");
	while(i < len)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	printf("%d\n", max(tab, len));

	return(0);	
}
