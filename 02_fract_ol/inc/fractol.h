/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:17:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/21 23:53:11 by marapovi         ###   ########.fr       */
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
# include <X11/X.h>
# include <X11/keysym.h>

#define WIDTH 	800
#define HEIGHT	800

#define DEFAULT_CENTRAL_BACKGROUND	0x000000
#define COLOR_SIZE					8
#define COLOR_COUNT					4

// Neon Sunset
#define FLAMING_ROSE			0xFF3E6B
#define TANGERINE_FLAME			0xFF8A00
#define HONEY_GLOW				0xFFD166

// Electric Ocean
#define AQUA_NEON				0x00E5FF
#define DEEP_AZURE				0x0074FF
#define ULTRAVIOLET_WAVE		0x6F00FF

// Cosmic Bloom
#define HOT_MAGENTA				0xFF1AC4
#define VIOLET_BLOOM			0x8A2BE2
#define SKY_RIPPLE				0x3A93FF

// Toxic Melody
#define ACID_LIME				0xCCFF00
#define MINT_SPARK				0x00FFC9
#define FUCHSIA_SHOCK			0xFF00FF

// Aurora Prism
#define SEAFOAM_GLEAM			0x7CFFCB
#define SOLAR_FLASH				0xFFD400
#define INDIGO_NIGHT			0x231FFD

// Shades of Grey
#define BLACK					0x000000
#define WHITE					0xFFFFFF
#define GREY					0x7F7F7F

// just bc of line-limit
typedef struct	s_atof
{
	double		result;
	double		div;
	long		sign;
	ssize_t		i;
}			t_atof;

// struct where to buffer image before rendering
typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	int			color;
}			t_img;

typedef struct	s_rgb
{
	int	r_min;
	int	g_min;
	int	b_min;
	int	r_max;
	int	g_max;
	int	b_max;
	int	r;
	int	g;
	int	b;
	int	color_variant[COLOR_COUNT][COLOR_SIZE];
	int	color_variant_index;
//	int	color_start;
//	int	color_end;
	int	code;
}			t_rgb;

// everything needed for creating and manipulating fractal
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
	t_rgb		*color;

}			t_fractal;

// complex number
typedef struct	s_complex
{
	double		x;
	double		y;
}			t_complex;

typedef struct	s_hsv
{
	double	c;
	double	hh;
	double	x;
	double	m;
	double	rf;
	double	gf;
	double	bf;
	int		r;
	int		g;
	int		b;
}		t_hsv;


// contains stucts/variables with allocated memory - needed for cleanup
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
void		fo_render(t_fractal *fractal, t_rgb *color);
void		fo_init_fractal(t_fractal *fractal, t_rgb *color);
void		fo_init_data(t_fractal *fractal, t_rgb *color);
void		fo_error_exit(t_clean *data);
//void		fo_put_pixel(t_img *data, int x, int y, t_rgb *color);
t_complex	fo_complex_square(t_complex z);
t_complex	fo_complex_sum(t_complex z1, t_complex z2);
void		fo_handle_pixel(int x, int y, t_fractal *fractal, t_rgb *color);
int			fo_handle_key(int keysym, t_fractal *fractal);
void		fo_init_events(t_fractal *fractal);
int			fo_handle_closing(t_fractal *fractal);
int			fo_handle_mouse(int button, t_fractal *fractal);
int			fo_track_julia(int x, int y, t_fractal *fractal);
void		fo_mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal);
int			fo_handle_color_keys(int keysym, t_fractal *fractal);
int			fo_set_color_channel(int color1, int color2, double mix_factor);
int			fo_make_color(int hex_min, int hex_max, double mix_factor);
void		fo_fill_color_variants_remainder(t_rgb *color);

#endif