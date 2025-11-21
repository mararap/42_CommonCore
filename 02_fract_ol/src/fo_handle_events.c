/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:39:33 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/21 23:00:09 by marapovi         ###   ########.fr       */
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
	t_rgb	*color;
	
	color = fractal->color;
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
		fractal->iter_def += 100;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
	{
		if (fractal->iter_def > 100)
			fractal->iter_def -= 100;
		if(fractal->iter_def < 1)
			fractal->iter_def = 1;
	}
	fo_handle_color_keys(keysym, fractal);
	fo_render(fractal, color);
	return (0);		
}

int	fo_handle_mouse(int button, t_fractal *fractal)
{
	t_rgb	*color;

	color = fractal->color;
	if (button == 5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == 4)
	{
		fractal->zoom *= 1.05;
	}
	fo_render(fractal, color);
	return (0);
}

int	fo_track_julia(int x, int y, t_fractal *fractal)
{
	t_rgb	*color;
	
	color = fractal->color;
	if (ft_strncmp(fractal->name, "julia", 6))
	{
		fractal->julia_x = fo_create_map(x, -2, +2, 0, WIDTH)
							* fractal->zoom + fractal->shift_x;
		fractal->julia_y = fo_create_map(y, +2, -2, 0, HEIGHT)
							* fractal->zoom + fractal->shift_y;
		fo_render(fractal, color);
	}
	return (0);
}

int	fo_handle_color_keys(int keysym, t_fractal *fractal)
{
	t_rgb	*color;
	
	color = fractal->color;
	if (keysym == XK_h || keysym == XK_H)
		color->color_variant_index = (color->color_variant_index - 1
								+ COLOR_COUNT)
								% COLOR_COUNT;
	else if (keysym == XK_l || keysym == XK_L)
		color->color_variant_index = (color->color_variant_index + 1)
								% COLOR_COUNT;
/*
	if (keysym == XK_Escape)
		fo_handle_closing(fractal);

	if (keysym == XK_0)
	{
		fractal->color1 = WHITE;
		fractal->color2 = BLACK;
//		fractal->color3 = GREY;
	}
	else if (keysym == XK_1)
	{
		fractal->color1 = FLAMING_ROSE;
		fractal->color2 = TANGERINE_FLAME;
//		fractal->color3 = HONEY_GLOW;		
	}
		else if (keysym == XK_2)
	{
		fractal->color1 = AQUA_NEON;
		fractal->color2 = DEEP_AZURE;
//		fractal->color3 = ULTRAVIOLET_WAVE;		
	}
		else if (keysym == XK_3)
	{
		fractal->color1 = HOT_MAGENTA;
		fractal->color2 = VIOLET_BLOOM;
//		fractal->color3 = SKY_RIPPLE;		
	}

	else if (keysym == XK_h || keysym == XK_H)
		fractal->color_variant_index = (fractal->color_variant_index - 1
								+ COLOR_COUNT)
								% COLOR_COUNT;
	else if (keysym == XK_l || keysym == XK_L)
		fractal->color_variant_index = (fractal->color_variant_index + 1)
								% COLOR_COUNT;
	fo_render(fractal);
*/
	return (0);
}
