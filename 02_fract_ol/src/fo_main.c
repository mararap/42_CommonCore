/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:55:37 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/20 16:44:19 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
/*
int	fo_run_julia(char **av)
{
	double	a;
	double	b;
	double	err;

	a = fo_atof(av[2]);
	b = fo_atof(av[3]);
	err = (double)((long)INT_MIN - 1);
	printf("a = %f\n", fo_atof(av[2]));
	printf("b = %f\n", fo_atof(av[3]));
	if (a == err || b == err)
	{
		write (1, "ERROR: invalid parameter\n", 25);
		return (1);
	}
	if (a < -2.0 || a > 2.0 || b < -2.0 || b > 2.0)
	{
		write(1, "ERROR: parameter must be between -2 and 2\n", 42);
		return (1);
	}
	return (fo_mlx_main());
}*/

int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if (!(ac == 2 || ac == 4))
		return (write(1, "wrong number of arguments\n", 26), 1);
	else if (((ac == 4) && (ft_strncmp(av[1], "Julia", 6) == 0))
		|| ((ac == 2) && (ft_strncmp(av[1], "Mandelbrot", 11) == 0)))
	{
		fractal.name = av[1];
		if (ft_strncmp(fractal.name, "Julia", 6) == 0)
		{
			fractal.julia_x = fo_atof(av[2]);
			fractal.julia_y = fo_atof(av[3]);
		}
		fo_fractal_init(&fractal);
		fo_render(&fractal);
		mlx_loop(fractal.init);
	}
	else
	{
		write (1, "unknown fractal\n", 16);
		exit(EXIT_FAILURE);
	}
	return (0);
}
