/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_handle_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:38:32 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/23 19:30:37 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	fo_set_color_channel(int color1, int color2, double mix_factor)
{
	double	new_color;
	int		rounded;

	if (mix_factor < 0.0)
		mix_factor = 0.0;
	if (mix_factor > 1.0)
		mix_factor = 1.0;
	new_color = (double)color1 + (double)(color2 - color1) * mix_factor;
	rounded = (int)round(new_color);
	if (rounded < 0)
		rounded = 0;
	if (rounded > 255)
		rounded = 255;
	return (rounded);
}

int	fo_make_color(int hex_min, int hex_max, t_fractal *fractal)
{
	fractal->color->r_min = (hex_min >> 16) & 0xFF;
	fractal->color->g_min = (hex_min >> 8) & 0xFF;
	fractal->color->b_min = hex_min & 0xFF;
	fractal->color->r_max = (hex_max >> 16) & 0xFF;
	fractal->color->g_max = (hex_max >> 8) & 0xFF;
	fractal->color->b_max = hex_max & 0xFF;
	fractal->color->r = fo_set_color_channel(fractal->color->r_min,
											fractal->color->r_max,
											fractal->color->mix_factor);
	fractal->color->g = fo_set_color_channel(fractal->color->g_min,
											fractal->color->g_max,
											fractal->color->mix_factor);
	fractal->color->b = fo_set_color_channel(fractal->color->b_min,
											fractal->color->b_max,
											fractal->color->mix_factor);
	return((fractal->color->r << 16) | (fractal->color->g << 8)
			| fractal->color->b);	
}

static void	fo_fill_color_variants_remainder(t_fractal *fractal)
{
	int	set;
	int	col;
	int	start;

	start = COLORS_PER_SET;
	set = 0;
	while (set < MAX_COLOR_SETS_COUNT)
	{
		if (start >= MAX_COLORS_PER_SET)
		{
			set++;
			continue ;
		}
		col = start;
		while (col < MAX_COLORS_PER_SET)
		{
			fractal->color->color_variant[set][col]
				= fractal->color->color_variant[set][start - 1];
			col++;
		}
		set++;
	}
}

void	fo_init_colors(t_fractal *fractal)
{
	fractal->color->color_variant[0][0]	= DEEP_SPACE_BG;
    fractal->color->color_variant[0][1]	= NEON_AQUA;
//    fractal->color->color_variant[0][2]	= HOT_PINK;

    fractal->color->color_variant[1][1]	= SOLAR_POP_BG;
//    fractal->color->color_variant[1][1]	= ELECTRIC_YELLOW;
    fractal->color->color_variant[1][0]	= TANGERINE_POP;

    fractal->color->color_variant[2][0]	= ARCTIC_BG;
//	  fractal->color->color_variant[2][1]	= ICE_CYAN;
    fractal->color->color_variant[2][1]	= LIME_SPARK;

    fractal->color->color_variant[3][0]	= NIGHT_CHALK_BG;
    fractal->color->color_variant[3][1]	= CHALK_WHITE;
//    fractal->color->color_variant[3][2]	= SLATE_BLUE;

    fractal->color->color_variant[4][1]	= EARTHEN_BG;
//    fractal->color->color_variant[4][1]	= BURNED_SAND;
    fractal->color->color_variant[4][0]	= EMERALD_SPRING;

    fractal->color->color_variant[5][0]	= INFERNO_BG;
//    fractal->color->color_variant[5][1]	= NEON_LIME;
    fractal->color->color_variant[5][1]	= ULTRA_VIOLET;

//	fractal->color->color_variant[6][0]	= VOLT_EMBER_BG;
    fractal->color->color_variant[6][0]	= VOLT_EMBER_LAVA;
    fractal->color->color_variant[6][1]	= VOLT_EMBER_CYAN;
	
/*	fractal->color->color_variant[5][0]	= INFERNO_BG;
	fractal->color->color_variant[5][1]	= NEON_LIME;
    fractal->color->color_variant[5][2]	= ULTRA_VIOLET;
	fractal->color->color_variant[0][0]	= FLAMING_ROSE;
	fractal->color->color_variant[0][1]	= TANGERINE_FLAME;
	fractal->color->color_variant[0][2]	= HONEY_GLOW;
	fractal->color->color_variant[1][0]	= AQUA_NEON;
	fractal->color->color_variant[1][1]	= DEEP_AZURE;
	fractal->color->color_variant[1][2]	= ULTRAVIOLET_WAVE;
	fractal->color->color_variant[2][0]	= SEAFOAM_GLEAM;
	fractal->color->color_variant[2][1]	= SOLAR_FLASH;
	fractal->color->color_variant[2][2]	= INDIGO_NIGHT;
	fractal->color->color_variant[3][0]	= BLACK;
	fractal->color->color_variant[3][1]	= WHITE;
	fractal->color->color_variant[3][2]	= GREY;
	fractal->color->color_variant[4][0]	= SANDSTONE;
	fractal->color->color_variant[4][1]	= OLIVE_DRAB;
	fractal->color->color_variant[4][2]	= MIDNIGHT_TEAL;
	fractal->color->color_variant[5][0]	= HOT_MAGENTA;
	fractal->color->color_variant[5][1]	= VIOLET_BLOOM;
	fractal->color->color_variant[5][2]	= SKY_RIPPLE;
	fractal->color->color_variant[6][0]	= SANDSTONE;
    fractal->color->color_variant[6][1]	= OLIVE_DRAB;
    fractal->color->color_variant[6][2]	= MIDNIGHT_TEAL;*/
	fo_fill_color_variants_remainder(fractal);
	fractal->color->color_variant_index	= 0;
}
