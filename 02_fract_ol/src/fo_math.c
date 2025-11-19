/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:00:13 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/19 23:13:26 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("malloc failed");
	exit(EXIT_FAILURE);
}

void	fo_fractal_init(t_fractal *fractal)
{
	fractal->init = mlx_init();
	
	if(fractal->init == NULL)
		error_exit(); TODO
	fractal->window = mlx_new_window(fractal, WIDTH, HEIGHT, fractal->name);
	if (fractal->window == NULL)
	{
		mlx_destroy_display(fractal->init);
		error_exit(); TODO
	}
	fractal->img.img_ptr = mlx_new_image(fractal->init, WIDTH, HEIGHT);	
	if (fractal->img.img_ptr == 0)
	{
		mlx_destroy_window(fractal->init, fractal->window);
		mlx_destroy_display(fractal->init);
		error_exit(); TODO
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.addr,
											&fractal->img.bits_per_pixel,
											&fractal->img.line_len,
											&fractal->img.endian);
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
			handle_pixel(x, y fractal);
			x++;
		}
		y++;
	}
}

double	scale_map(double unscaled, double new_min, double new_max,
					double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled - old_min)
			/ (old_max - old_min) + new_min);
}
void	handle_pixel (int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0
	z.y = 0.0;
	i = 0;
	c.x = scale_map(x, -2, +2, 0, WIDTH);
	c.y = scale_map(y, +2, -2, 0, HEIGHT);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map{i, BLACK, WHITE};
			fo_pixel_put();
			return ;
		}
	}
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;
	
	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
}