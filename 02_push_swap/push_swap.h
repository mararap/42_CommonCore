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

# include <stdio.h> // REMOVE BEFORE SUBMITTING //
# include <unistd.h> //write, read
# include <stdbool.h> //true - false
# include <limits.h> //int_max - int_min
# include <stdlib.h> //malloc, free
# include <stddef.h> // ? //

typedef struct s_stack
{
	long					nbr;
	long					index;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

void		ft_parse_args(char **av, t_stack **stack_a);
void		ft_add_last(t_stack **stack, t_stack *new_node);
t_stack		*ft_new_node(int value);
t_stack		*ft_parsing(int ac, char **av);
char		**ft_split(char const *s, char c);

#endif //!PUSH_SWAP_H
