/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:00:13 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/21 12:57:41 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_fractal_init(t_fractal *fractal)
{
	t_clean	data;

	data = (t_clean){0};
	fractal->init = mlx_init();	
	if(fractal->init == NULL)
		fo_error_exit(&data);
	data.init = fractal->init;
	fractal->window = mlx_new_window(fractal->init,
									WIDTH,
									HEIGHT,
									fractal->name);
	if (fractal->window == NULL)
		fo_error_exit(&data);
	fractal->img.ptr = mlx_new_image(fractal->init, WIDTH, HEIGHT);	
	if (fractal->img.ptr == 0)
		fo_error_exit(&data);
	fractal->img.addr = mlx_get_data_addr(fractal->img.ptr,
											&fractal->img.bits_per_pixel,
											&fractal->img.line_len,
											&fractal->img.endian);
	fo_events_init(fractal);
	fo_data_init(fractal);
}

void	fo_render(t_fractal *fractal)
{
	int	x;
	int	y;
	
	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fo_handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->init,
							fractal->window,
							fractal->img.ptr,
							0, 0);
}

double	fo_create_map(double unscaled, double new_min, double new_max,
					double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled - old_min)
			/ (old_max - old_min) + new_min);
}

void	fo_mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
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
	}
}

void	fo_handle_pixel (int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (fo_create_map(x, -2, +2, 0, WIDTH) * fractal->zoom)
		+ fractal->shift_x;
	z.y = (fo_create_map(y, +2, -2, 0, HEIGHT)* fractal->zoom)
		+ fractal->shift_y;
	fo_mandel_or_julia(&z, &c, fractal);
	while (i < fractal->iter_def)
	{
		z = fo_complex_sum(fo_complex_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = fo_create_map(i, BLACK, WHITE, 0, fractal->iter_def);
			fo_put_pixel(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	fo_put_pixel(&fractal->img, x, y, BLACK);
}

t_complex	fo_complex_sum(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	fo_complex_square(t_complex z)
{
	t_complex	result;
	
	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

void	fo_data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iter_def = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}