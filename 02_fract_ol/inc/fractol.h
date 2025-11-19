/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:17:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/19 23:07:51 by marapovi         ###   ########.fr       */
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

#define WIDTH 500
#define HEIGHT 500

#define ORANGE 0xF59127
#define PINK 0xF527F5
#define BLUE 0x231FFD
#define GREEN 0x27F527

typedef struct	s_atof
{
	double	result;
	double	div;
	long	sign;
	ssize_t	i;
}				t_atof;

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_fractal
{
	void	*init;
	void	*window;
	t_img	img;
	
}				t_fractal;

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

int			main(int ac, char **av);
int			fo_mlx_main(void);
double		fo_atof(char *av);
int			fo_is_space(char c);
double		scale_map(double unscaled, double new_min, double new_max,
					double old_min, double old_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);

#endif