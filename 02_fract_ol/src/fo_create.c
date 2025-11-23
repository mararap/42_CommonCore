/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:20:54 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/23 02:00:12 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fo_mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "Julia", 6) == 0)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
		z->x = 0.0;
		z->y = 0.0;
	}
}

static void	fo_put_pixel(int x, int y, t_fractal *fractal)
{
	int	offset;
	
	if (!(fractal->img.addr))
		return ;
	offset = (y * fractal->img.line_len + (x * (fractal->img.bits_per_pixel / 8)));
	*(unsigned int *)(fractal->img.addr + offset) = fractal->color->code;
}

static void	fo_pixel_to_complex(int x, int y, t_fractal *fractal, t_complex *z)
{
	z->x = (fo_create_map(x, -2, +2, 0, WIDTH)
		* fractal->zoom) + fractal->shift_x;
	z->y = (fo_create_map(y, +2, -2, 0, HEIGHT)
		* fractal->zoom) + fractal->shift_y;
}

static int	fo_iter_to_color(t_fractal *fractal, int iter)
{
	int		idx;
	int		start;
	int		end;
	
	if (fractal->color->color_variant_index < 0
		|| fractal->color->color_variant_index >= MAX_COLOR_SETS_COUNT)
		fractal->color->color_variant_index = 0;
	idx = fractal->color->color_variant_index;
	start =	fractal->color->color_variant[idx][0];
	end = fractal->color->color_variant[idx][2];
	if (start == 0)
		start = BLACK;
	if (end == 0)
		end = WHITE;
	if (iter >= fractal->iter_def || fractal->iter_def == 0)
		return (fractal->color->color_variant[idx][0]);
	fractal->color->mix_factor = (double)iter / (double)fractal->iter_def;
	return (fo_make_color(start, end, fractal));
}
/*
static int	fo_iter_to_color(t_fractal *fractal, int iter)
{
	int	row;
	int	num_escape;
	int	bucket;
	int	idx;

	if (fractal->color->color_variant_index < 0
		|| fractal->color->color_variant_index >= MAX_COLOR_SETS_COUNT)
		fractal->color->color_variant_index = 0;
	row = fractal->color->color_variant_index;
	if (iter >= fractal->iter_def || fractal->iter_def == 0)
		return (fractal->color->color_variant[row][1]);
	num_escape = COLORS_PER_SET - 1;
	if (num_escape <= 0)
	{
		if (COLORS_PER_SET > 1)
			idx = 1;
		else
			idx = 0;
		return (fractal->color->color_variant[row][idx]);
	}
	bucket = (int)((long long)iter * fractal->iter_def - iter * num_escape);
	if (bucket < 0)
		bucket = 0;
	if (bucket >= num_escape)
		bucket = num_escape - 1;
	return (fractal->color->color_variant[row][1 + bucket]);
}*/

static void	fo_no_escape(t_fractal *fractal, t_complex *z, int x, int y)
{
	int		idx;
	int		start;
	int		end;
	double	radius;
	double	inv_sqrt_escape;
	
	idx = fractal->color->color_variant_index;
	start = fractal->color->color_variant[idx][0];
	end = fractal->color->color_variant[idx][2];
	inv_sqrt_escape = 1.0 / sqrt((double)fractal->escape_value);
	radius = sqrt((z->x * z->x) + (z->y * z->y));
	fractal->color->mix_factor = radius * inv_sqrt_escape;
	if (fractal->color->mix_factor < 0.0)
		fractal->color->mix_factor = 0.0;
	if (fractal->color->mix_factor > 1)
		fractal->color->mix_factor = 1;
	fractal->color->code = fo_make_color(start, end, fractal);
	fo_put_pixel(x, y, fractal);
}

void	fo_handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	
	c.x = 0;
	c.y = 0;
	i = 0;
	fo_pixel_to_complex(x, y, fractal, &z);
	fo_mandel_or_julia(&z, &c, fractal);
	fractal->color->code = fo_iter_to_color(fractal, fractal->iter_def);
	while (i < fractal->iter_def)
	{
		z = fo_complex_sum(fo_complex_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			fractal->color->code = fo_iter_to_color(fractal, i);
			fo_put_pixel(x, y, fractal);
			break ;
		}
		i++;
	}
	fo_no_escape(fractal, &z, x, y);
	fo_put_pixel(x, y, fractal);
}

