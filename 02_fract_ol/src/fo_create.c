/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:20:54 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/23 20:38:59 by marapovi         ###   ########.fr       */
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
	offset = (y * fractal->img.line_len
			+ (x * (fractal->img.bits_per_pixel / 8)));
	*(unsigned int *)(fractal->img.addr + offset) = fractal->color->code;
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
	start = fractal->color->color_variant[idx][0];
	end = fractal->color->color_variant[idx][COLORS_PER_SET - 1];
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
static void	fo_no_escape(t_fractal *fractal, t_complex *z)
{
    int	idx;

    (void)z;
    idx = fractal->color->color_variant_index;
    fractal->color->code = fractal->color->color_variant[idx][0];
}*/

static void	fo_no_escape(t_fractal *fractal, t_complex *z)
{
	int		idx;
	int		start;
	int		end;
	double	radius;
	double	inv_sqrt_escape;
	
    if (fractal->is_mandelbrot)
    {
        int idx = fractal->color->color_variant_index;
        fractal->color->code = fractal->color->color_variant[idx][0];
        return ;
    }
	idx = fractal->color->color_variant_index;
	start = fractal->color->color_variant[idx][0];
	end = fractal->color->color_variant[idx][2];
	inv_sqrt_escape = 1.0 / sqrt((double)fractal->escape_value);
	radius = sqrt(((z->x * z->x) + (z->y * z->y)) *inv_sqrt_escape);
	fractal->color->mix_factor = radius * inv_sqrt_escape;
	if (fractal->color->mix_factor < 0.0)
		fractal->color->mix_factor = 0.0;
	if (fractal->color->mix_factor > 1.0)
		fractal->color->mix_factor = 1.0;
	fractal->color->code = fo_make_color(start, end, fractal);
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
	while (i < fractal->iter_def)
	{
		z = fo_complex_sum(fo_complex_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			fractal->color->code = fo_iter_to_color(fractal, i);
			fo_put_pixel(x, y, fractal);
			return ;
		}
		i++;
	}
	fo_no_escape(fractal, &z);
	fo_put_pixel(x, y, fractal);
}
