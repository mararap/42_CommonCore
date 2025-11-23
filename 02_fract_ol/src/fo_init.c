/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:30:44 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/22 22:43:54 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_render(t_fractal *fractal)
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
				fo_handle_pixel(x, y, fractal);
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

static int	fo_track_julia(int x, int y, t_fractal *fractal)
{	
	if (ft_strncmp(fractal->name, "Julia", 6))
	{
		fractal->julia_x = fo_create_map(x, -2, +2, 0, WIDTH)
							* fractal->zoom + fractal->shift_x;
		fractal->julia_y = fo_create_map(y, +2, -2, 0, HEIGHT)
							* fractal->zoom + fractal->shift_y;
		fo_render(fractal);
	}
	return (0);
}

static void	fo_init_events(t_fractal *fractal)
{
	mlx_hook(fractal->window,
			KeyPress,
			KeyPressMask,
			fo_handle_keys,
			fractal);

	mlx_hook(fractal->window,
			ButtonPress,
			ButtonPressMask,
			fo_handle_mouse,
			fractal);

	mlx_hook(fractal->window,
			MotionNotify,
			PointerMotionMask,
			fo_track_julia,
			fractal);
			
	mlx_hook(fractal->window,
			DestroyNotify,
			StructureNotifyMask,
			fo_handle_closing,
			fractal);
}

static void	fo_init_data(t_fractal *fractal)
{
	fractal->escape_value		 	= 4;
	fractal->iter_def 				= 100;
	fractal->shift_x 				= 0.0;
	fractal->shift_y 				= 0.0;
	fractal->zoom 					= 1.0;
	fractal->color = (t_rgb *)ft_calloc(1, sizeof(t_rgb));
	if (!fractal->color)
		fo_error_exit(fractal);
	fractal->color->mix_factor = 0.0;
	fo_init_colors(fractal);
}

void	fo_init_fractal(t_fractal *fractal)
{
	fractal->init = mlx_init();	
	if(fractal->init == NULL)
		fo_error_exit(fractal);
	fractal->window = mlx_new_window(fractal->init,
									WIDTH,
									HEIGHT,
									fractal->name);
	if (fractal->window == NULL)
		fo_error_exit(fractal);
	fractal->img.ptr = mlx_new_image(fractal->init, WIDTH, HEIGHT);	
	if (fractal->img.ptr == 0)
		fo_error_exit(fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.ptr,
											&fractal->img.bits_per_pixel,
											&fractal->img.line_len,
											&fractal->img.endian);
	fo_init_events(fractal);
	fo_init_data(fractal);
}

