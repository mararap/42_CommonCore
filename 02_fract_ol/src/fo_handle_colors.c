/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_handle_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:38:32 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/21 23:45:01 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	fo_set_color_channel(int color1, int color2, double mix_factor)
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

int	fo_make_color(int hex_min, int hex_max, double mix_factor)
{
	t_rgb	color;
	
	color.r_min = (hex_min >> 16) & 0xFF;
	color.g_min = (hex_min >> 8) & 0xFF;
	color.b_min = hex_min & 0xFF;
	color.r_max = (hex_max >> 16) & 0xFF;
	color.g_max = (hex_max >> 8) & 0xFF;
	color.b_max = hex_max & 0xFF;
	color.r = fo_set_color_channel(color.r_min, color.r_max, mix_factor);
	color.g = fo_set_color_channel(color.g_min, color.g_max, mix_factor);
	color.b = fo_set_color_channel(color.b_min, color.b_max, mix_factor);
	return((color.r << 16) | (color.g << 8) | color.b);	
}

void	fo_fill_color_variants_remainder(t_rgb *color)
{
	int	p;
	int	i;

	p = 0;
	while (p < 3)
	{
		i = 3;
		while (i < COLOR_SIZE)
		{
			color->color_variant[p][i] = color->color_variant[p][2];
			i++;
		}
		p++;
	}
	i = 0;
	while (i < COLOR_SIZE)
	{
		color->color_variant[3][i] = BLACK;
		i++;
	}
}

void	fo_init_colors(t_rgb *color)
{
	color->color_variant[0][0]	= FLAMING_ROSE;
	color->color_variant[0][1]	= TANGERINE_FLAME;
	color->color_variant[0][2]	= HONEY_GLOW;
	color->color_variant[1][0]	= AQUA_NEON;
	color->color_variant[1][1]	= DEEP_AZURE;
	color->color_variant[1][2]	= ULTRAVIOLET_WAVE;
	color->color_variant[2][0]	= SEAFOAM_GLEAM;
	color->color_variant[2][1]	= SOLAR_FLASH;
	color->color_variant[2][2]	= INDIGO_NIGHT;
	fo_fill_color_variants_remainder(color);

	color->color_variant_index	= 0;
}

void	fo_init_data(t_fractal *fractal, t_rgb *color)
{
	fractal->escape_value		 	= 4;
	fractal->iter_def 				= 100;
	fractal->shift_x 				= 0.0;
	fractal->shift_y 				= 0.0;
	fractal->zoom 					= 1.0;
	fo_init_colors(color);
}
