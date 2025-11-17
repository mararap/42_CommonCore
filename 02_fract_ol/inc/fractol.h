/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:17:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/17 20:46:09 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <libft.h>
# include <mlx.h>
# include <limits.h>

typedef struct	s_atof
{
	double	result;
	double	div;
	long	sign;
	ssize_t	i;
}				t_atof;

typedef struct	s_fractol
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_fractol;

int			main(int ac, char **av);
int			fo_mlx_main(void);
double		fo_atof(char *av);
int			fo_is_space(char c);

#endif