/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:39:33 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/21 14:12:34 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fo_handle_closing(t_fractal *fractal)
{
	mlx_destroy_image(fractal->init,
					fractal->img.ptr);
	mlx_destroy_window(fractal->init,
					fractal->window);
	mlx_destroy_display(fractal->init);
	free(fractal->init);
	exit(EXIT_SUCCESS);
}

int	fo_handle_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		fo_handle_closing(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus || keysym == XK_equal || keysym == XK_KP_Add)
		fractal->iter_def += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
	{
		if (fractal->iter_def > 10)
			fractal->iter_def -= 10;
		if(fractal->iter_def < 1)
			fractal->iter_def = 1;
	}
	fo_render(fractal);
	return (0);		
}

int	fo_handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;

	if (button == 5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == 4)
	{
		fractal->zoom *= 1.05;
	}
	fo_render(fractal);
	return (0);
}

int	fo_track_julia(int x, int y, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 6))
	{
		fractal->julia_x = fo_create_map(x, -2, +2, 0, WIDTH)
							* fractal->zoom + fractal->shift_x;
		fractal->julia_y = fo_create_map(y, +2, -2, 0, HEIGHT)
							* fractal->zoom + fractal->shift_y;
		fo_render(fractal);
	}
	return (0);
}
