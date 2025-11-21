/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_mlx_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:33 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/21 12:47:59 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;
	
	offset = (y * img->line_len + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)(img->addr + offset) = color;
}

void	fo_events_init(t_fractal *fractal)
{
	mlx_hook(fractal->window,
			KeyPress,
			KeyPressMask,
			fo_handle_key,
			fractal);

	mlx_hook(fractal->window,
			ButtonPress,
			ButtonPressMask,
			fo_handle_mouse,
			fractal);
			
	mlx_hook(fractal->window,
			DestroyNotify,
			StructureNotifyMask,
			fo_handle_closing,
			fractal);
}
/*
int	fo_mlx_main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	int			x;
	int			y;

	x = WIDTH;
	y = HEIGHT;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HEIGHT, WIDTH,
		"###########  F R A C T O L  ###########");
	img.ptr = mlx_new_image(mlx, HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel,
		&img.line_len, &img.endian);
	while (y < HEIGHT)
	{
		x = WIDTH * 0.1;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&img, x, y, rand() % 0x1000000);
				x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.ptr, 0, 0);
	mlx_loop(mlx);
	return (0);
}*/
