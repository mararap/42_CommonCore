/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:17:25 by pjelinek          #+#    #+#             */
/*   Updated: 2025/10/06 23:57:35 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char *a, char *b)
{
	char	temp = *a;

	*a = *b;
	*b = temp;
}

void	sort_string(char *str, int i)
{
	int	j;

	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

void	permute(char *str, int start)
{
	int	i;
	int	len;

	if (!str[start])
	{
		len = 0;
		while (str[len])
			len++;
		write(1, str, len);
		write(1, "\n", 1);
		return ;
	}
	i = start;
	while (str[i])
	{
		ft_swap(&str[i], &str[start]);
		sort_string(str, start + 1);
		permute(str, start + 1);
		ft_swap(&str[start], &str[i]);
		i++;
	}
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	main(int ac, char **argv)
{
	if (ac == 2)
	{
		int i = 0;
		while (argv[1][i])
    	{
        	if (!ft_isalpha(argv[1][i]))
            	return (write(1, "Error\n", 6), 1);
        	i++;
    	}
		sort_string(argv[1], 0);
		permute(argv[1], 0);
	}
	return (0);
}
