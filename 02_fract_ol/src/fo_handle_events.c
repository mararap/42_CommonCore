/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_handle_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:39:33 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/25 18:10:11 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fo_handle_closing(t_fractal *fractal)
{
	fo_cleanup(fractal);
	exit(0);
}

static int	fo_handle_color_keys(int keysym, t_fractal *fractal)
{
	t_rgb	*color;

	color = &fractal->color;
	if (keysym == XK_h || keysym == XK_H)
		color->color_variant_index = (color->color_variant_index - 1
				+ COLOR_SETS_COUNT) % COLOR_SETS_COUNT;
	else if (keysym == XK_l || keysym == XK_L)
		color->color_variant_index = (color->color_variant_index + 1)
			% COLOR_SETS_COUNT;
	return (0);
}

static void	fo_handle_iter_keys(int keysym, t_fractal *fractal)
{
	if (keysym == XK_plus || keysym == XK_equal || keysym == XK_KP_Add)
	{
		fractal->iter_def += 100;
		if (fractal->iter_def > ITER_MAX)
			fractal->iter_def = ITER_MAX;
	}
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
	{
		if (fractal->iter_def > 100)
			fractal->iter_def -= 100;
		if (fractal->iter_def < 1)
			fractal->iter_def = 1;
	}
}

int	fo_handle_keys(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		fo_handle_closing(fractal);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	fo_handle_iter_keys(keysym, fractal);
	fo_handle_color_keys(keysym, fractal);
	fo_render(fractal);
	return (0);
}

int	fo_handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractal->zoom *= 0.80;
	else if (button == 5)
		fractal->zoom *= 1.20;
	fo_render(fractal);
	return (0);
}
