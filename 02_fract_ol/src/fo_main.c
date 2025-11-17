/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:55:37 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/17 18:31:15 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	fo_display_julia(char **av)
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
}

int	main(int ac, char **av)
{
	if (ac < 2 || ac > 4)
		return (write(1, "wrong number of arguments\n", 26), 1);
	if (ft_strncmp(av[1], "Julia", 6) == 0)
	{
		write(1, "Julia\n", 6);
		return (fo_display_julia(av));
	}
	else if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
	{
		write(1, "Mandelbrot\n", 11);
		// call display mandelbrot
		return (fo_mlx_main());
	}
	write (1, "unknown fractal\n", 16);
	return (1);
}
