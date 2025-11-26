/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:40:24 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/26 17:26:06 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_cleanup(t_fractal *fractal)
{
	if (fractal->img.ptr)
		mlx_destroy_image(fractal->init, fractal->img.ptr);
	if (fractal->window)
		mlx_destroy_window(fractal->init, fractal->window);
	if (fractal->init)
		mlx_destroy_display(fractal->init);
	free(fractal->init);
}

void	fo_exit_error(t_fractal *fractal)
{
	fo_cleanup(fractal);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	fo_exit_success(t_fractal *fractal)
{
	fo_cleanup(fractal);
	exit(EXIT_SUCCESS);
}

void	fo_prompt(void)
{
	ft_printf("\nmissing or invalid argument(s)\n");
	ft_printf("\navailable options (case sensitive):\n");
	ft_printf("\nMandelbrot\nJulia <double> <double>\n\n");
	ft_printf("interesting parameters for Julia:\n");
	ft_printf(" 0.0   &  0.8  \n 0.355 &  0.355\n-0.4   & -0.59 \n");
	ft_printf(" 0.37  &  0.1  \n-0.54  &  0.54 \n-0.74  &  0.06 \n\n");
}

void	fo_prompt_cleanup_exit(t_fractal *fractal)
{
	fo_prompt();
	fo_exit_success(fractal);
}
