/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:30:44 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/25 18:07:23 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_render(t_fractal *fractal)
{
	int	x;
	int	y;
	int	step;

	step = 8;
	while (step >= 1)
	{
		y = 0;
		while (y < HEIGHT)
		{
			x = 0;
			while (x < WIDTH)
			{
				fo_handle_pixel(x, y, fractal);
				x += step;
			}
			y += step;
		}
		mlx_put_image_to_window(fractal->init, fractal->window,
			fractal->img.ptr, 0, 0);
		step = step * 0.5;
	}
}

static void	fo_init_events(t_fractal *fractal)
{
	mlx_hook(fractal->window, KeyPress, KeyPressMask,
		fo_handle_keys, fractal);
	mlx_hook(fractal->window, ButtonPress, ButtonPressMask,
		fo_handle_mouse, fractal);
	mlx_hook(fractal->window, DestroyNotify, StructureNotifyMask,
		fo_handle_closing, fractal);
}

static void	fo_init_data(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iter_def = 100;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color.mix_factor = 0.0;
	fractal->color.color_variant_index = 0;
	if (!(ft_strncmp(fractal->name, "Mandelbrot", 10)))
		fractal->is_mandelbrot = 1;
	fo_init_colors(fractal);
}

void	fo_init_fractal(t_fractal *fractal)
{
	fractal->init = mlx_init();
	if (fractal->init == NULL)
		fo_exit_error(fractal);
	fractal->window = mlx_new_window(fractal->init, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->window == NULL)
		fo_exit_error(fractal);
	fractal->img.ptr = mlx_new_image(fractal->init, WIDTH, HEIGHT);
	if (fractal->img.ptr == 0)
		fo_exit_error(fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_len,
			&fractal->img.endian);
	fo_init_events(fractal);
	fo_init_data(fractal);
}
