/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:07:01 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/25 12:52:11 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> //write, read
# include <limits.h> //int_max - int_min
# include <stdlib.h> //malloc, free
# include "./inc/libft/libft.h"
# include <stdbool.h> //true/false
# include <sys/types.h> // ssize_t


typedef	struct s_stack
{
	ssize_t	*curr_pos;
	int		*value;
	ssize_t	size;
}			t_stack;

typedef struct s_ps_v
{
	ssize_t		len_a;
	ssize_t		len_b;
}				t_ps_v;

char 			*ps_input(char **av);
long			ps_atol_check(char *str);
t_stack			*ps_isvalid(char **split_input, ssize_t size);
ssize_t			ps_wcount(char *s);
bool			ps_issorted(t_stack stack);
void    		ft_free_av(char **av);
void   			 ps_free_all(t_stack *stack, char **av, char *input);
t_stack	  		*ps_free_NULL(t_stack *stack, char **av, char *input);

#endif // !PUSH_SWAP_H
