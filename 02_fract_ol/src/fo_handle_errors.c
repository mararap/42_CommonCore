/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:40:24 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/23 22:51:51 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_cleanup(t_fractal *fractal)
{
	if (fractal && fractal->color)
		free(fractal->color);
	if (fractal->init && fractal->img.ptr)
	{
		mlx_destroy_image(fractal->init, fractal->img.ptr);
		if (fractal->window)
			mlx_destroy_window(fractal->init, fractal->window);
	}
	if (fractal->init)
		mlx_destroy_display(fractal->init);
	free(fractal->init);
}

void	fo_error_exit(t_fractal *fractal)
{
	fo_cleanup(fractal);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	fo_error_success(t_fractal *fractal)
{
	fo_cleanup(fractal);
	exit(EXIT_SUCCESS);
}

void	fo_prompt_exit(void)
{
	ft_printf("\nmissing or invalid argument(s)\n\navailable options:\n");
	ft_printf("Mandelbrot\nJulia <double> <double>\n\n");
	ft_printf("interesting parameters for Julia:\n");
	ft_printf("0.0 0.8\n0.355 0.355\n-0.4 -0.59\n0.37 0.1\n-0.54 0.54\n");
	exit(EXIT_FAILURE);
}

void	fo_prompt_cleanup_exit(t_fractal *fractal)
{
	ft_printf("\nmissing or invalid argument(s)\n\navailable options:\n");
	ft_printf("Mandelbrot\nJulia <double> <double>\n\n");
	ft_printf("interesting parameters for Julia:\n");
	ft_printf("0.0 0.8\n0.355 0.355\n-0.4 -0.59\n0.37 0.1\n-0.54 0.54\n");
	fo_cleanup(fractal);
	exit(1);
}
