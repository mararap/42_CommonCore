/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 00:26:04 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/30 00:35:05 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sort_int_tab(int *tab, unsigned int size)
{
	int	tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < (size - 1))
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j]
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
