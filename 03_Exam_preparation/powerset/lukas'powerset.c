/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwittwer <lwittwer@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:59:06 by lwittwer          #+#    #+#             */
/*   Updated: 2025/11/23 00:41:25 by lwittwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*num;
int	n;

void	search(int index, int target, int currentSum, int subSet[], int subsetSize)
{
	int	i = 0;
	if (index == n)
	{
		if (currentSum == target)
		{
			while (i < subsetSize)
			{
				printf("%d ", subSet[i]);
				i++;
			}
			printf("\n");
		}
		return;
	}
	search(index + 1, target, currentSum, subSet, subsetSize);
	subSet[subsetSize] = num[index];
	search(index + 1, target, currentSum + num[index], subSet, subsetSize + 1);
}

int	main(int argc, char **argv)
{
	int	*arr;
	int	target;
	int	subset[100];
	int	i = 2;
	int	j = 0;

	arr = malloc((argc - 2) * sizeof(int));
	if (!arr)
		return (1);
	while (i < argc)
	{
		arr[j] = atoi(argv[i]);
		j++;
		i++;
	}
	num = arr;
	n = argc - 2;
	target = atoi(argv[1]);
	printf("Subsets that sum to %d:\n", target);
	search(0, target, 0, subset, 0);
	free(arr);
	return (0);
}
