/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:53:34 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/11 12:13:47 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_list(t_node *head)
{
	t_node	*current;

	current = head;
	while (current)
	{
		ft_printf("%ld -> ", current->value);
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_node	*stack_a;

	if (ac <2)
		return (0);

	stack_a = ft_parsing(ac, av);
	ft_print_list(stack_a);
	ft_free_list(stack_a);

	return (0);
}
