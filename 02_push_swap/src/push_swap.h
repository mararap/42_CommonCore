/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:07:01 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/19 17:31:02 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // REMOVE BEFORE SUBMITTING !!! //
# include <unistd.h> //write, read
# include <limits.h> //int_max - int_min
# include <stdlib.h> //malloc, free
# include "../inc/libft/libft.h"
# include <stdbool.h>

typedef	struct s_ps
{
	long	index;
	long	value;
}			t_ps;

typedef struct s_ps_v
{
	int		len_a;
	int		len_b;
}			t_ps_v;

int					main(int ac, char **av);
long				ps_atol_check(char *str);
void				ps_free_str_arr(char **str_arr);
void				ps_isvalid(char c, t_ps *stack_a, t_ps *stack_b);
t_ps 				*ps_parse_multi(t_ps *stack_a, char **arr, int len);
char 				**ps_parse_one(char *str, t_ps *stack_a, t_ps *stack_b);
long				ps_isvalid_sign(char a, char b);
size_t				ps_arr_of_str_len(char **arr);
bool				ps_doub(t_ps *arr, long num, int i);
void				ps_handle_error(t_ps *stack_a, t_ps *stack_b);
void				ps_free_stack(t_ps *stack);
t_ps				ps_parsing(t_ps *stack_a, )

/*
typedef struct s_node
{
	long			nbr;
	long			index;
	long			*stack_a;
//	struct s_node	*next;
//	struct s_node	*prev;
}					t_node;*/

// void		ft_parse_args(char **av, t_node **stack_a, size_t i);
// void		ft_add_last(t_node **stack, t_node *new_node);
// t_node		*ft_new_node(long nbr);
// t_node		*ft_parsing(int ac, char **av);
// t_node		*ft_parse_quoted(char **av);
// void		ft_print_error();
// t_node		*ft_last_node(t_node *end);
// void		ft_free_str_arr(char **str_arr);
// void		ft_print_list(t_node *head);
// void		ft_free_list(t_node *head);

#endif // !PUSH_SWAP_H
