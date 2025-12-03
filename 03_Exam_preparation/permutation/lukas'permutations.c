/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwittwer <lwittwer@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:24:50 by lwittwer          #+#    #+#             */
/*   Updated: 2025/11/23 15:40:39 by lwittwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putstr(char *str)
{
	write(0, str, ft_strlen(str));
	write(0, "\n", 1);
}
void	swap(char *a, char *b)
{
	char	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	permute(char *str, int left, int right)
{
	int	i = left;
	if (left == right)
	{
		ft_putstr(str);
		return;
	}
	while (i <= right)
	{
		swap(&str[left], &str[i]);
		permute(str, left + 1, right);
		swap(&str[left], &str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	permute(argv[1], 0, ft_strlen(argv[1]) - 1);
	return (0);
}
