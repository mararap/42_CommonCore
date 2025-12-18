/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lukas'permutations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:24:50 by lwittwer          #+#    #+#             */
/*   Updated: 2025/12/12 20:05:05 by marapovi         ###   ########.fr       */
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
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
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

int	main(int ac, char **av)
{
	if (ac != 2 || av[1] == NULL || ft_strlen(av[1]) == 0)
		return (1);
	(void)ac;
	permute(av[1], 0, ft_strlen(av[1]) - 1);
	return (0);
}
