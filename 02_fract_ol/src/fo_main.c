/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:55:37 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/23 22:50:57 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (!(ac == 2 || ac == 4) || ((ac == 4) && (!av[2][0] || !av[3][0])))
		return (fo_prompt_exit(), 1);
	else if (((ac == 4) && (ft_strncmp(av[1], "Julia", 6) == 0))
		|| ((ac == 2) && (ft_strncmp(av[1], "Mandelbrot", 11) == 0)))
	{
		fractal.name = av[1];
		if (ft_strncmp(fractal.name, "Julia", 6) == 0)
		{
			fractal.julia_x = fo_atof(av[2], &fractal);
			fractal.julia_y = fo_atof(av[3], &fractal);
		}
		fo_init_fractal(&fractal);
		fo_render(&fractal);
		mlx_loop(fractal.init);
	}
	else
		fo_prompt_exit();
	return (0);
}
