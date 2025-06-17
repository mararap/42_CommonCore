/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwarz <bschwarz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:46:07 by bschwarz          #+#    #+#             */
/*   Updated: 2025/06/05 13:40:45 by bschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	void	*ptr;
	void	*ptr2 = NULL;
	char	*s = "Teststring";
	char	*t = NULL;
	int		n = -1337;
	int		i;

	printf("FT_PRINTF TESTS:\n");
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT: This is the way ");
	printf("%d                         |\n", i);
	i = printf("| OG: This is the way ");
	printf("%d                         |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_char: %c ", 'c');
	printf("%d                                  |\n", i);
	i = printf("| OG_char: %c ", 'c');
	printf("%d                                  |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_string: %s ", s);
	printf("%d                       |\n", i);
	i = printf("| OG_string: %s ", s);
	printf("%d                       |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_pointer: %p ", ptr);
	printf("%d                          |\n", i);
	i = printf("| OG_pointer: %p ", ptr);
	printf("%d                          |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_number: %d ", INT_MIN);
	printf("%d                      |\n", i);
	i = printf("| OG_number: %d ", INT_MIN);
	printf("%d                      |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_integer: %i ", n);
	printf("%d                       |\n", i);
	i = printf("| OG_integer: %i ", n);
	printf("%d                       |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_unsigned decimal: %u ", n);
	printf("%d              |\n", i);
	i = printf("| OG_unsigned decimal: %u ", n);
	printf("%d              |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_hexlow: %x ", n);
	printf("%d                         |\n", i);
	i = printf("| OG_hexlow: %x ", n);
	printf("%d                         |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_hexup: %X ", n);
	printf("%d                          |\n", i);
	i = printf("| OG_hexup: %X ", n);
	printf("%d                          |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_symbol: %% ");
	printf("%d                                |\n", i);
	i = printf("| OG_symbol: %% ");
	printf("%d                                |\n", i);
	printf("--------------------------------------------------\n");
	printf("| FT_empty: ");
	i = ft_printf("");
	printf("%d                                    |\n", i);
	printf("| OG_empty: ");
	i = printf("");
	printf("%d                                    |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_mix: %s, %x, %p ", s, n, ptr);
	printf("%d        |\n", i);
	i = printf("| OG_mix: %s, %x, %p ", s, n, ptr);
	printf("%d        |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_same: %s, %s, %s ", s, s, s);
	printf("%d |\n", i);
	i = printf("| OG_same: %s, %s, %s ", s, s, s);
	printf("%d |\n", i);
	printf("--------------------------------------------------\n");
	i = ft_printf("| FT_null: %s, %p ", t, ptr2);
	printf("%d                      |\n", i);
	i = printf("| OG_null: %s, %p ", t, ptr2);
	printf("%d                      |\n", i);
	printf("--------------------------------------------------\n");
	return (0);
}