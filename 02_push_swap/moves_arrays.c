/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:07:26 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/04 13:55:08 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h> //delete before submitting!!!
//swap a

void ft_rotate(int	size, int *arr)
{
	int	i;
	int	temp;

	temp = arr[0];
	i = 0;
	while(i < size - 2)
	{
		arr[i] = arr[i+1];
		i++;
	}
	arr[i] = temp;
	return ;
}

void ft_rrotate(int	size, int *arr)
{
	int	i;
	int	temp;

	temp = arr[size - 1];
	i = size - 1;
	while(i > 0)
	{
		arr[i] = arr[i-1];
		i--;
	}
	arr[i] = temp;
	return ;
}

//swap b
//swap both
//rotate a
//rotate b
//rotate both
//reverse rotate a
//reverse rotate b
//reverse rotate both
//push (a to) b
//push (b to) a
//pop?
//
