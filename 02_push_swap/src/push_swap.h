/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:07:01 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/16 13:15:44 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // REMOVE BEFORE SUBMITTING !!! //
# include <unistd.h> //write, read
# include <limits.h> //int_max - int_min
# include <stdlib.h> //malloc, free
# include "../inc/libft/libft.h"

typedef	struct s_ps
{
	int 	*item;
//	int		*index;
	int		len;
}			t_ps;

int					main(int ac, char **av);
long				ps_atol_check(char *str, int *error);
void				ps_free_str_arr(char **str_arr);
int					ps_isvalid(char c);
t_ps 				*ps_parse_multi(t_ps *stack, char **arr, int *error);
char 				**ps_parse_one(char *str, int *error);
int					ps_isvalid_sign(char a, char b);
size_t				ps_arr_of_str_len(char **arr);
int					ps_doub(int *arr, int num, int i);
void				ps_handle_error(int error, t_ps *stack);

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
