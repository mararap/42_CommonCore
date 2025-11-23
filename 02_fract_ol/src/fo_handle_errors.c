/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:40:24 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/22 22:08:32 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_cleanup(t_fractal *fractal)
{
	if(fractal && fractal->color)
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
	exit(1);
}

void	fo_error_success(t_fractal *fractal)
{
	fo_cleanup(fractal);
	exit(EXIT_SUCCESS);
}
