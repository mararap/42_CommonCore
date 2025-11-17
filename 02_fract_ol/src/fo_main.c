/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:55:37 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/17 11:54:34 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if (ac < 2 || ac > 4)
		return (write(1, "wrong number of arguments\n", 26), 1);
	if (ft_strncmp(av[1], "Julia", 6) == 0)
	{
		if (av[2])
			(void)av[2];
		if (av[3])
			(void)av[3];
		return (fo_mlx_main());
	}
	else if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
	{
		if (av[2])
			(void)av[2];
		if (av[3])
			(void)av[3];
		return (fo_mlx_main());
	}
	write (1, "unknown fractal\n", 16);
	return (1);
}
