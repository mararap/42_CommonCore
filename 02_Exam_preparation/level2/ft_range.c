/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:02:43 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/22 16:36:14 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_range_len(int start, int end)
{
	int	len;

	if (start < 0)
		start *= -1;
	if (end < 0)
		end *= -1;
	len = start + end + 1;
	printf("len = %d\n", len);
	return(len);
}

int	*ft_range(int start, int end)
{
	int	*arr;
	int	len;
	int	i;

	i = 0;
	len = ft_range_len(start, end);
	arr = malloc(len);
	while(start <= end)
	{
		arr[i] = start;
		start++;
		i++;
	}
	return (arr);
}

int	main()
{
	int	start = -3;
	int	end = 1;
	int	*arr = ft_range(start, end);
	printf("arr = %p\n", ((void *)arr));
	return (0);
}
