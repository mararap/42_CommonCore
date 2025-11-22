/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:20:54 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/22 17:46:21 by marapovi         ###   ########.fr       */
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

static void	fo_put_pixel(t_img *img, int x, int y, t_rgb *color)
{
	int	offset;
	
	if (!img || !img->addr)
		return ;
	offset = (y * img->line_len + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)(img->addr + offset) = color->code;
}

static void	fo_pixel_to_complex(int x, int y, t_fractal *fractal, t_complex *z)
{
	z->x = (fo_create_map(x, -2, +2, 0, WIDTH)
		* fractal->zoom) + fractal->shift_x;
	z->y = (fo_create_map(y, +2, -2, 0, HEIGHT)
		* fractal->zoom) + fractal->shift_y;
}

static int	fo_inter_to_color(t_fractal *fractal, t_rgb *color, int iter)
{
	int		idx;
	int		start;
	int		end;
	
	if (color->color_variant_index < 0
		|| color->color_variant_index >= MAX_COLOR_SETS_COUNT)
		color->color_variant_index = 0;
	idx = color->color_variant_index;
	start =	color->color_variant[idx][0];
	end = color->color_variant[idx][1];
	if (start == 0)
		start = GREY;
	if (end == 0)
		end = WHITE;
	return (fo_make_color(start, end,
						(double)iter/(double)fractal->iter_def));
}

void	fo_handle_pixel(int x, int y, t_fractal *fractal, t_rgb *color)
{
	t_complex	z;
	t_complex	c;
	int			i;
	
	c.x = 0;
	c.y = 0;
	i = 0;
	fo_pixel_to_complex(x, y, fractal, &z);
	fo_mandel_or_julia(&z, &c, fractal);
	color->code = DEFAULT_CENTRAL_BACKGROUND;
	while (i < fractal->iter_def)
	{
		z = fo_complex_sum(fo_complex_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color->code = fo_inter_to_color(fractal, color, i);
			fo_put_pixel(&fractal->img, x, y, color);
			break ;
		}
		i++;
	}
	fo_put_pixel(&fractal->img, x, y, color);
}
