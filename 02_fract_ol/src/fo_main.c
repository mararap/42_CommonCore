/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:55:37 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/25 18:14:22 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fo_range_prompt(void)
{
	ft_printf("\nFor visible output,\n");
	ft_printf("use params between -2.0 and 2.0.\n\n");
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	ft_bzero(&fractal, sizeof(t_fractal));
	if (((ac == 4) && (ft_strncmp(av[1], "Julia", 6) == 0))
		|| ((ac == 2) && (ft_strncmp(av[1], "Mandelbrot", 11) == 0)))
	{
		fractal.name = av[1];
		if (ft_strncmp(fractal.name, "Julia", 6) == 0)
		{
			if (fo_atof(av[2], &fractal) >= 2 || fo_atof(av[2], &fractal) <= -2
				|| fo_atof(av[3], &fractal) >= 2
				|| fo_atof(av[3], &fractal) <= -2)
				fo_range_prompt();
			fractal.julia_x = fo_atof(av[2], &fractal);
			fractal.julia_y = fo_atof(av[3], &fractal);
		}
		ft_printf("\nUse arrow keys to move around.\n");
		ft_printf("Use + and - to increase/decrease iterations.\n");
		ft_printf("use h or l to switch colors.\n\n");
		fo_init_fractal(&fractal);
		fo_render(&fractal);
		mlx_loop(fractal.init);
	}
	else
		fo_prompt_cleanup_exit(&fractal);
}
