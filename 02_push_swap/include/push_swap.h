/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:07:01 by marapovi          #+#    #+#             */
/*   Updated: 2025/08/11 19:07:05 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // REMOVE BEFORE SUBMITTING !!! //
# include <unistd.h> //write, read
# include <stdbool.h> //true - false
# include <limits.h> //int_max - int_min
# include <stdlib.h> //malloc, free
# include <stddef.h> // ? //
# include "../libft/libft.h"

typedef struct s_node
{
	long			nbr;
	long			index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void		ft_parse_args(char **av, t_node **stack_a, size_t i);
void		ft_add_last(t_node **stack, t_node *new_node);
t_node		*ft_new_node(long nbr);
t_node		*ft_parsing(int ac, char **av);
t_node		*ft_parse_quoted(char **av);
void		ft_print_error();
t_node		*ft_last_node(t_node *end);
void		ft_free_strv(char **strv);
void		ft_print_list(t_node *head);
void		ft_free_list(t_node *head);

#endif // !PUSH_SWAP_H
