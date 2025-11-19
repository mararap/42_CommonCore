/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:00:13 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/19 21:39:58 by marapovi         ###   ########.fr       */
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

void	fractal_render(t_fractal *fractal)
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