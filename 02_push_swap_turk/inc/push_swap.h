/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:59:15 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/16 19:51:29 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>	// write, read
# include <limits.h>	// int_max - int_min
# include <stdlib.h>	// malloc, free
# include <libft.h>		// libft
# include <stdbool.h>	// true/false
# include <sys/types.h>	// ssize_t

typedef struct s_node
{
	int				value;
	int				curr_pos;
	int				cost;
	bool			above_med;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

char	*ps_input(char **av);
ssize_t	ps_wcount(char *s);
bool	ps_isdoub(t_node **stack, int value);
void	ps_stack_init(t_node **stack, char *input);
void	ps_append(t_node **stack, int value);
long	ps_atol_check(char *str);
bool	ps_space(char c);
ssize_t	ps_stacklen(t_node *stack);
t_node	*ps_find_max(t_node *stack);
t_node	*ps_find_min(t_node *stack);
t_node	*ps_find_tail(t_node *head);
void	ps_push(t_node **src, t_node **dest, char dest_name);
void	ps_sa(t_node **a);
void	ps_sb(t_node **b);
void	ps_ss(t_node **a, t_node **b);
void	ps_ra(t_node **a);
void	ps_rb(t_node **b);
void	ps_rr(t_node **a, t_node **b);
void	ps_rra(t_node **a);
void	ps_rrb(t_node **b);
void	ps_rrr(t_node **a, t_node **b);
void	ps_sort(t_node **a, t_node **b);
bool	ps_issorted(t_node *stack);
void	ps_min_to_top(t_node **a);
void	ps_push_prep(t_node **a, t_node **b);
t_node	*ps_find_cheapest(t_node *b);
void	ps_nodes_init(t_node *a, t_node *b);
void	ps_set_curr(t_node *stack);
void	ps_free_stack(t_node **stack);
void	ft_free_av(char **av);
void	ps_error_exit(t_node **a, t_node **b, char **av, char *input);
void	ps_free_all(t_node **a, t_node **b, char **av, char *input);

#endif