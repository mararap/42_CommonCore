/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:07:01 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/24 22:49:19 by marapovi         ###   ########.fr       */
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


typedef	struct s_ps
{
	long	index;
	long	value;
}			t_ps;

typedef struct s_ps_v
{
	ssize_t		len_a;
	ssize_t		len_b;
}				t_ps_v;

char 			*ps_input(char **av);
long			ps_atol_check(char *str);
int				*ps_isvalid(char **split_input, ssize_t size);
ssize_t			ps_wcount(char *s);
bool			ps_isdoub(int *arr, int num, ssize_t i);

#endif // !PUSH_SWAP_H
