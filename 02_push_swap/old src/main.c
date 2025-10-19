/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:52 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 21:42:44 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char    **input_str;
	char	*temp;
	char	*result;
	t_ps    *stack_a = NULL;
	t_ps    *stack_b = NULL;
	size_t  i = 1;
	size_t  len = ac - 1;
	int		j = 0;

	if (ac == 1)
		return (2);
	/* only allocate stack_b if needed later; parsing functions allocate stack_a */
	if (ac >= 2)
	{
		while (av[i])
		{
			j = 0;
			input_str = ps_parse_str(av[i]);
			while (input_str[j])
			{
				if(ps_find_char(input_str[j], 32))
					input_str = ps_parse_str(input_str[j]);
				
				result = ft_strjoin(result, " ");
				result = ft_strjoin(result, input_str[j]);
				len += j;
				j++;
			}
			result = ft_strlcat(temp, j);
			len += i;
			i++;
		}
	}
	/*else if (ac > 2)
	{
		// pass pointer to first value (av + 1) and count ac - 1
		stack_a = ps_parse_multi(stack_a, av + 1, ac - 1);
		len = (size_t)(ac - 1);
		if (!stack_a)
			ps_handle_error(stack_a, stack_b);
	}*/
	i = 0;
	printf("stack_a =");
	while (i < len && stack_a)
	{
		printf(" %ld", stack_a[i].value);
		i++;
	}
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	return (0);
}
