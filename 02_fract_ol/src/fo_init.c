/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:30:44 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/21 23:48:09 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fo_color_map(int iter, t_fractal *fractal, t_rgb *color)
{
	int idx;
	int	p;

	if (iter >= fractal->iter_def || fractal->iter_def == 0)
		return (color->color_variant[color->color_variant_index][0]);
	p = color->color_variant_index;
	idx = (iter * (COLOR_SIZE - 1)) / fractal->iter_def;
	return (color->color_variant[p][idx + 1]);
}

void	fo_render(t_fractal *fractal, t_rgb *color)
{
	int	x;
	int	y;
	int	step;
	
	step = 8;
	while(step >= 1)
	{
		y = 0;
		while(y < HEIGHT)
		{
			x = 0;
			while (x < WIDTH)
			{
				fo_handle_pixel(x, y, fractal, color);
				x += step;
			}
			y += step;
		}
		mlx_put_image_to_window(fractal->init,
								fractal->window,
								fractal->img.ptr,
								0, 0);
		step = step * 0.5;
		}
}

void	fo_init_fractal(t_fractal *fractal, t_rgb *color)
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
	fractal->color = color;
	fo_init_events(fractal);
	fo_init_data(fractal, color);
}

void	fo_init_events(t_fractal *fractal)
{
	mlx_hook(fractal->window,
			KeyPress,
			KeyPressMask,
			fo_handle_key,
			fractal);

	mlx_hook(fractal->window,
			ButtonPress,
			ButtonPressMask,
			fo_handle_mouse,
			fractal);
			
	mlx_hook(fractal->window,
			DestroyNotify,
			StructureNotifyMask,
			fo_handle_closing,
			fractal);
}