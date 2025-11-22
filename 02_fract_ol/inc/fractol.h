/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:17:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/22 18:15:25 by marapovi         ###   ########.fr       */
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

#define WIDTH 	400
#define HEIGHT	400

#define	ITER_MAX 200000

#define DEFAULT_CENTRAL_BACKGROUND	0x000000
#define	MAX_COLORS_PER_SET			8
#define COLORS_PER_SET				3
#define	MAX_COLOR_SETS_COUNT		20
#define COLOR_SETS_COUNT			7
/*
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

// Terra Twilight
#define SANDSTONE				0xC97E5D
#define OLIVE_DRAB				0x6B8E23
#define MIDNIGHT_TEAL			0x003F5C

#define NEON_LIME				0x00FF66
#define SLATE_DUSK				0x2F4F4F
#define ELECTRIC_PURPLE			0x8A00FF
*/
// just bc of line-limit
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
	int	variant[MAX_COLOR_SETS_COUNT][MAX_COLORS_PER_SET];
	int	variant_index;
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
double		fo_atof(char *av);
double		fo_create_map(double unscaled, double new_min, double new_max,
					double old_min, double old_max);
void		fo_render(t_fractal *fractal, t_rgb *color);
void		fo_init_fractal(t_fractal *fractal, t_rgb *color);
//void		fo_init_data(t_fractal *fractal, t_rgb *color);
void		fo_error_exit(t_clean *data);
//void		fo_put_pixel(t_img *data, int x, int y, t_rgb *color);
t_complex	fo_complex_square(t_complex z);
t_complex	fo_complex_sum(t_complex z1, t_complex z2);

// events

//void		fo_init_events(t_fractal *fractal);
void		fo_handle_pixel(int x, int y, t_fractal *fractal, t_rgb *color);
int			fo_handle_keys(int keysym, t_fractal *fractal);
int			fo_handle_closing(t_fractal *fractal);
int			fo_handle_mouse(int button, int x, int y, t_fractal *fractal);
//int			fo_track_julia(int x, int y, t_fractal *fractal);
//void			fo_mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal);
//int			fo_handle_color_keys(int keysym, t_fractal *fractal);
//int			fo_set_color_channel(int color1, int color2, double mix_factor);

// colors

void		fo_init_colors(t_rgb *color);
int			fo_make_color(int hex_min, int hex_max, double mix_factor);
//void		fo_fill_color_variants_remainder(t_rgb *color);

#endif