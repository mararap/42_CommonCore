/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:17:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/20 19:54:28 by marapovi         ###   ########.fr       */
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

#define WIDTH 800
#define HEIGHT 800

#define ORANGE 0xF59127
#define PINK 0xF527F5
#define BLUE 0x231FFD
#define GREEN 0x27F527
#define BLACK 0x000000
#define WHITE 0xFFFFFF

typedef struct	s_atof
{
	double		result;
	double		div;
	long		sign;
	ssize_t		i;
}			t_atof;

typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	int			color;
}			t_img;

typedef struct	s_fractal
{
	void		*init;
	void		*window;
	t_img		img;
	int			escape_value;
	int			iter_def;
	char		*name;
	double		shift_x;
	double		shift_y;
	double		julia_x;
	double 		julia_y;
	double		zoom;
	
}			t_fractal;

typedef struct	s_complex
{
	double		x;
	double		y;
}			t_complex;

typedef struct	s_clean
{
	t_fractal	*fractal;
	t_img		img;
	void		*window;
	void		*init;
}			t_clean;


int			main(int ac, char **av);
int			fo_mlx_main(void);
double		fo_atof(char *av);
int			fo_is_space(char c);
double		fo_create_map(double unscaled, double new_min, double new_max,
					double old_min, double old_max);
t_complex	fo_square_complex(t_complex z);
t_complex	fo_sum_complex(t_complex z1, t_complex z2);
void		fo_render(t_fractal *fractal);
int			fo_key_handler(int keysym, t_fractal *fractal);
void		fo_fractal_init(t_fractal *fractal);
void		fo_data_init(t_fractal *fractal);
void		fo_error_exit(t_clean *data);
void		fo_pixel_put(t_img *data, int x, int y, int color);
t_complex	fo_complex_square(t_complex z);
t_complex	fo_complex_sum(t_complex z1, t_complex z2);
void		fo_handle_pixel (int x, int y, t_fractal *fractal);


#endif