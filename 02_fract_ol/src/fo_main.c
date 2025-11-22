/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:55:37 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/22 18:14:36 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;
	t_rgb		color;
	
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
		fo_init_fractal(&fractal);
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
