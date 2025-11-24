/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:17:41 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/24 19:23:46 by marapovi         ###   ########.fr       */
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

# define WIDTH 600
# define HEIGHT 600

# define ITER_MAX 2000

# define DEFAULT_CENTRAL_BACKGROUND	0x000000
# define MAX_COLORS_PER_SET			8
# define COLORS_PER_SET				2
# define MAX_COLOR_SETS_COUNT		20
# define COLOR_SETS_COUNT			7

// Shades of Grey
# define BLACK					0x000000
# define WHITE					0xFFFFFF
# define GREY					0x7F7F7F

/* High-contrast dark palettes */
# define DEEP_SPACE_BG		0x05030A  /* very dark navy */
# define NEON_AQUA			0x00FFD5  /* bright cyan */
# define HOT_PINK			0xFF2D95  /* vivid magenta */

# define SOLAR_POP_BG		0x0B0400  /* near-black warm */
# define ELECTRIC_YELLOW	0xFFD400  /* bright yellow */
# define DARK_ORANGE		0xF56127  /* dark orange */

# define ARCTIC_BG			0x041A2B  /* deep blue-black */
# define ICE_CYAN			0x66F0FF  /* bright icy cyan */
# define LIME_SPARK			0xB6FF00  /* bright lime */

# define NIGHT_CHALK_BG		0x000000  /* true black */
# define CHALK_WHITE		0xFFFFFF  /* white */
# define SLATE_BLUE			0x6C8EA4  /* bluish slate */

# define EARTHEN_BG			0x07140E  /* dark green-brown */
# define BURNED_SAND		0xC97E5D  /* warm sandstone */
# define EMERALD_SPRING		0x00C853  /* bright green */

# define INFERNO_BG			0x100006  /* very dark maroon */
# define NEON_LIME			0xA8FF00  /* neon lime */
# define ULTRA_VIOLET		0x8A00FF  /* bright violet */

# define VOLT_EMBER_BG		0x080308  /* very dark purple-black */
# define VOLT_EMBER_LAVA	0xFF4500  /* vivid ember orange */
# define VOLT_EMBER_CYAN	0x00F0E0  /* bright cyan accent */

/*
// Funky Color Palettes //
// Neon Sunset
#define FLAMING_ROSE			0xFF3E6B
#define TANGERINE_FLAME			0xFF8A00
#define HONEY_GLOW				0xFFD166

// Electric Ocean
#define AQUA_NEON				0x00E5FF
#define DEEP_AZURE				0x0074FF
#define ULTRAVIOLET_WAVE		0x6F00FF

// Terra Twilight
#define SANDSTONE				0xC91AC4
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

// Terra Twilight
#define SANDSTONE				0xC97E5D
#define OLIVE_DRAB				0x6B8E23
#define MIDNIGHT_TEAL			0x003F5C

#define NEON_LIME				0x00FF66
#define SLATE_DUSK				0x2F4F4F
#define ELECTRIC_PURPLE			0x8A00FF*/

// just bc of line-limit
typedef struct s_atof
{
	double		result;
	double		div;
	long		sign;
	ssize_t		i;
}			t_atof;

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}			t_img;

typedef struct s_rgb
{
	int		r_min;
	int		g_min;
	int		b_min;
	int		r_max;
	int		g_max;
	int		b_max;
	double	mix_factor;
	int		r;
	int		g;
	int		b;
	int		color_variant[MAX_COLOR_SETS_COUNT][MAX_COLORS_PER_SET];
	int		color_variant_index;
	int		code;
}			t_rgb;

// everything needed for creating and manipulating fractal
typedef struct s_fractal
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
	double		julia_y;
	double		zoom;
	t_rgb		color;
	int			is_mandelbrot;

}			t_fractal;

// complex number
typedef struct s_complex
{
	double		x;
	double		y;
}			t_complex;

int			main(int ac, char **av);
double		fo_atof(char *av, t_fractal *fractal);
void		fo_init_fractal(t_fractal *fractal);
void		fo_render(t_fractal *fractal);
double		fo_create_map(double unscaled, double new_min, double new_max,
				double old_max);

// error handling
void		fo_exit_error(t_fractal *fractal);
void		fo_exit_success(t_fractal *fractal);
void		fo_cleanup(t_fractal *fractal);
void		fo_prompt(void);
void		fo_prompt_cleanup_exit(t_fractal *fractal);

// math
t_complex	fo_complex_square(t_complex z);
t_complex	fo_complex_sum(t_complex z1, t_complex z2);
void		fo_pixel_to_complex(int x, int y, t_fractal *fractal, t_complex *z);

// events
void		fo_handle_pixel(int x, int y, t_fractal *fractal);
int			fo_handle_keys(int keysym, t_fractal *fractal);
int			fo_handle_closing(t_fractal *fractal);
int			fo_handle_mouse(int button, int x, int y, t_fractal *fractal);

// colors
void		fo_init_colors(t_fractal *fractal);
int			fo_make_color(int hex_min, int hex_max, t_fractal *fractal);

#endif
